#include <string.h>

#include <unistd.h>
#include <pwd.h>

#include "sgx_urts.h"
#include "Enclave_u.h"
#include "LibSgxExample.h"

#define MAX_PATH FILENAME_MAX

/* EID shared by multiple threads */
sgx_enclave_id_t global_eid = 0;

/* Function: Initialize the enclave:
 *   Step 1: try to retrieve the launch token saved by last transaction
 *   Step 2: call sgx_create_enclave to initialize an enclave instance
 *   Step 3: save the launch token if it is updated
 */
extern "C" int ctypes_initialize_enclave(void)
{
    char token_path[MAX_PATH] = {'\0'};
    sgx_launch_token_t token = {0};
    sgx_status_t ret = SGX_ERROR_UNEXPECTED;
    int updated = 0;
    /* Step 1: try to retrieve the launch token saved by last transaction 
     *         if there is no token, then create a new one.
     */
    /* try to get the token saved in $HOME */
    const char *home_dir = getpwuid(getuid())->pw_dir;
    
    if (home_dir != NULL && 
        (strlen(home_dir)+strlen("/")+sizeof(TOKEN_FILENAME)+1) <= MAX_PATH) {
        /* compose the token path */
        strncpy(token_path, home_dir, strlen(home_dir));
        strncat(token_path, "/", strlen("/"));
        strncat(token_path, TOKEN_FILENAME, sizeof(TOKEN_FILENAME)+1);
    } else {
        /* if token path is too long or $HOME is NULL */
        strncpy(token_path, TOKEN_FILENAME, sizeof(TOKEN_FILENAME));
    }

    FILE *fp = fopen(token_path, "rb");
    if (fp == NULL && (fp = fopen(token_path, "wb")) == NULL) {
        printf("Warning: Failed to create/open the launch token file \"%s\".\n", token_path);
    }

    if (fp != NULL) {
        /* read the token from saved file */
        size_t read_num = fread(token, 1, sizeof(sgx_launch_token_t), fp);
        if (read_num != 0 && read_num != sizeof(sgx_launch_token_t)) {
            /* if token is invalid, clear the buffer */
            memset(&token, 0x0, sizeof(sgx_launch_token_t));
            printf("Warning: Invalid launch token read from \"%s\".\n", token_path);
        }
    }
    /* Step 2: call sgx_create_enclave to initialize an enclave instance */
    /* Debug Support: set 2nd parameter to 1 */
    ret = sgx_create_enclave(ENCLAVE_FILENAME, SGX_DEBUG_FLAG, &token, &updated, &global_eid, NULL);
    if (ret != SGX_SUCCESS) {
        if (fp != NULL) fclose(fp);
        return -1;
    }

    /* Step 3: save the launch token if it is updated */
    if (updated == FALSE || fp == NULL) {
        /* if the token is not updated, or file handler is invalid, do not perform saving */
        if (fp != NULL) fclose(fp);
        return 0;
    }

    /* reopen the file with write capablity */
    fp = freopen(token_path, "wb", fp);
    if (fp == NULL) return 0;
    size_t write_num = fwrite(token, 1, sizeof(sgx_launch_token_t), fp);
    if (write_num != sizeof(sgx_launch_token_t))
        printf("Warning: Failed to save launch token to \"%s\".\n", token_path);
    fclose(fp);
    return 0;
}

/* Function: Destroy the enclave */
extern "C" void ctypes_sgx_destroy_enclave(void)
{
    sgx_status_t ret = SGX_ERROR_UNEXPECTED;
    ret = sgx_destroy_enclave(global_eid);
    if (ret != SGX_SUCCESS) {
        printf("Failed to destroy eclave: INVALID_ENCLAVE_ID.\n");
    }
}


/* Function: Generate random byte array within enclave */
extern "C" unsigned char* ctypes_ecall_sgx_read_rand(int len, unsigned char *byteArrayPtr)
{    
    /* Utilize trusted libraries */
    printf("\nTest: Generating sgx random number ... ...\n");
    sgx_status_t ret = SGX_ERROR_UNEXPECTED;
    ret = ecall_sgx_read_rand(global_eid, byteArrayPtr, len);
    if (ret != SGX_SUCCESS)
        abort();

    printf("C byte array char[%d] test after SGX running:\n", len);
    for (int i = 0; i < len; i++) {
        printf("%x ", *(byteArrayPtr + i));
    }
    printf("\n");

    return byteArrayPtr;
}

