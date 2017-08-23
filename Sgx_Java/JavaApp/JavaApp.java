import LibSgxJava.*;

class JavaApp {
    public static void main(String args[]){
 
        SgxFunction sgxFunctionTest = new SgxFunction();
        
        /*Initialize enclave */
        int initEnclaveStat = -1;
        initEnclaveStat = sgxFunctionTest.jni_initialize_enclave();
        if (initEnclaveStat < 0) {
            System.out.print("Failed to initiate enclave! Exiting...");
            return;
        }
        System.out.println("Successfully initialized enclave!");

        /*Generate an array with random elements and output the array to untrusted memory from enclave */
        int len = 8;
        if (args.length > 0) {
            len = Integer.parseInt(args[0]);
        }

        byte[] testJavaArray = new byte[len];

        System.out.print("JAVA byte array byte[" + len + "] before SGX running:\n");   

	for (int i = 0; i < len; i++) {
		System.out.print(" " + Integer.toHexString(testJavaArray[i] & 0xFF));
	}

	System.out.print("\n");

        /*Calling the sgx_read_rand function */
        testJavaArray = sgxFunctionTest.jni_ecall_sgx_read_rand(testJavaArray);
        
        System.out.print("JAVA byte array byte[" + len + "] after SGX running:\n");

	for (int i = 0; i < len; i++) {
		System.out.print(Integer.toHexString(testJavaArray[i] & 0xFF) + " ");
	}

	System.out.print("\n");

        /*Destroy the enclave */
        sgxFunctionTest.jni_sgx_destroy_enclave();
    }
}





        






