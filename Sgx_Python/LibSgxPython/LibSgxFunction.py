from ctypes import *
import sys

class SgxFunction:

	def __init__(self, lib_path = 'libSgx.so'):
		self.lib_sgx = CDLL(lib_path)

	# Initialize the enclave #
	def sgxfunction_initialize_enclave(self):
		init_enclave_stat = self.lib_sgx.ctypes_initialize_enclave()
		if (init_enclave_stat < 0):
			sys.exit("Failed to initiate enclave! Exiting...")
		print("Successfully initialized enclave!")
		return

	# Ecall random number generator in enclave #
	def sgxfunction_ecall_sgx_read_rand(self, bytes_number):
		# define the return type of the native C function to None as the C function 
		# takes the pointer of random_byte_array and modifies it in place 		
		self.lib_sgx.ctypes_ecall_sgx_read_rand.restype = None
		random_byte_array = (c_char * bytes_number)()
		self.lib_sgx.ctypes_ecall_sgx_read_rand(len(random_byte_array), random_byte_array)
		return random_byte_array

	# Destroy the enclave #
	def sgxfunction_sgx_destroy_enlave(self):
		self.lib_sgx.ctypes_sgx_destroy_enclave()
		return
