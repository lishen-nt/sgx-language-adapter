package LibSgxGo

/*
#cgo CFLAGS: -I../LibSgxC -I/opt/intel/sgxsdk/include
#cgo LDFLAGS: -L.. -lSgx
#include <LibSgxExample.h>
#include <stdlib.h>
#include <stdio.h>
*/
import "C"
import (
	"fmt"
)

func Initialize_Enclave() {
	C.cgo_initialize_enclave()
}

func Ecall_Sgx_Read_Rand(byteArrayLen int) []byte {

	byteArray := make([] byte, byteArrayLen, byteArrayLen)
	
	fmt.Printf("Original GoLang byteArray is:\n")	
	for i := 0; i < byteArrayLen; i++ {

		fmt.Printf("%02x ", byteArray[i])
	}
	fmt.Printf("\n")

	C.cgo_ecall_sgx_read_rand((C.int)(byteArrayLen), (*C.uchar)(&byteArray[0]))

	return byteArray
}

func Sgx_Destroy_Enclave() {		
	C.cgo_sgx_destroy_enclave()
}
