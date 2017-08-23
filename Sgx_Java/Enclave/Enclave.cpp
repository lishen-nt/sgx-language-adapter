#include <string.h>
#include <sgx_cpuid.h>

#include "sgx_trts.h"
#include "Enclave.h"
#include "Enclave_t.h"

/* ecall_sgx_read_rand:
 *   Uses sgx_read_rand to generate true random numbers.
 */

void ecall_sgx_read_rand(unsigned char *ptr, int len)
{
    sgx_status_t ret = sgx_read_rand(ptr, len);
    if (ret != SGX_SUCCESS)
        abort();
}
