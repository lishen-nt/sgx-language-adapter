package main

import (
	"fmt"
	"./LibSgxGo"
	"flag"
)


func main() {
	// use flag -len to define the lenth of the array, default value is 8
	arrayLen := flag.Int("len", 8, "an int")
	flag.Parse()
	
	LibSgxGo.Initialize_Enclave()
	byteArray := LibSgxGo.Ecall_Sgx_Read_Rand(*arrayLen)
	fmt.Printf("\nGenerated GoLang byteArray is:\n")	
	for i := 0; i < *arrayLen; i++ {

		fmt.Printf("%02x ", byteArray[i])
	}
	fmt.Printf("\n")
	LibSgxGo.Sgx_Destroy_Enclave()
}
