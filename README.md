# sgx-language-adapter

## Sgx_Java

The project demonstrates several fundamental example APIs created with Java Native Interface (JNI). These example APIs enavle JAVA to perform enclave operations in Intel(R) Software Guard Extensions (SGX).
- Initialize and destroy an enclave.
- Generate a random byte array using SGX trusted library function (sgx_read_rand).

### How to Build/Execute the Sample Code

- Install Intel(R) SGX SDK for Linux* OS
- Install OpenJDK (sudo apt-get install openjdk-8-jdk)
- export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`
- Build the project with the prepared Makefile:
    1. Hardware Mode, Debug build:
        $ make
    2. Hardware Mode, Pre-release build:
        $ make SGX_PRERELEASE=1 SGX_DEBUG=0
    3. Hardware Mode, Release build:
        $ make SGX_DEBUG=0
    4. Simulation Mode, Debug build:
        $ make SGX_MODE=SIM
    5. Simulation Mode, Pre-release build:
        $ make SGX_MODE=SIM SGX_PRERELEASE=1 SGX_DEBUG=0
    6. Simulation Mode, Release build:
        $ make SGX_MODE=SIM SGX_DEBUG=0
- Execute example Java app:
    $ java JavaApp [size of byte array]
- Remember to "make clean" before switching build mode


## Sgx_Python

coming...
