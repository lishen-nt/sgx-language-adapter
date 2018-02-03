
#ifndef _LIBSGXEXAMPLE_H_
#define _LIBSGXEXAMPLE_H_


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <sgx_error.h>       /* sgx_status_t */
#include <sgx_eid.h>     /* sgx_enclave_id_t */

#ifndef TRUE
# define TRUE 1
#endif

#ifndef FALSE
# define FALSE 0
#endif

# define TOKEN_FILENAME   "enclave.token"
# define ENCLAVE_FILENAME "enclave.signed.so"

extern sgx_enclave_id_t global_eid;    /* global enclave id */

#if defined(__cplusplus)
extern "C" {
#endif

int cgo_initialize_enclave(void);
void cgo_sgx_destroy_enclave(void);
unsigned char* cgo_ecall_sgx_read_rand(int len, unsigned char *byteArrayPtr);

#if defined(__cplusplus)
}
#endif

#endif /* !_LIBSGXEXAMPLE_H_ */
