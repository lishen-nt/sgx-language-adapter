# add LibSgxPython's path to sys.path
import sys
import os.path
libdir = os.path.abspath(os.path.join(os.path.dirname(__file__), 'LibSgxPython'))
sys.path.append(libdir)

import LibSgxFunction

def main():
	
	if len(sys.argv) > 1:
		length = int(sys.argv[1])
	else:
		length = 8

	sgxFunctionTest = LibSgxFunction.SgxFunction()

	sgxFunctionTest.sgxfunction_initialize_enclave()

	testArray = sgxFunctionTest.sgxfunction_ecall_sgx_read_rand(length)
	print ("\nPython byte array array[" + str(length) + "] after SGX running")
	print (" ".join("{0:x}".format(ord(c)) for c in testArray))

	sgxFunctionTest.sgxfunction_sgx_destroy_enlave()

if __name__ == "__main__":
	main()
