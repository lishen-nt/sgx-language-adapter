package LibSgxJava;

public class SgxFunction {
    static {
        System.loadLibrary("Sgx");
    }

    /* Initialize the enclave */
    public native int jni_initialize_enclave();

    /* Ecall random number generator in enclave */
    public native byte[] jni_ecall_sgx_read_rand(byte[] randArr);

    /* Destroy the enclave */
    public native void jni_sgx_destroy_enclave();
}
