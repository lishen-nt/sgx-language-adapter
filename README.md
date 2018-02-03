# sgx-language-adapter

## Sgx_Java

The project demonstrates several fundamental example APIs created with Java Native Interface (JNI). These example APIs enable JAVA to perform enclave operations in Intel(R) Software Guard Extensions (SGX).

### How to Build/Execute the Sample Code

- Install Intel(R) SGX SDK for Linux* OS
- Install OpenJDK (sudo apt-get install openjdk-8-jdk)
- export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:\`pwd\`
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

The project demonstrates several fundamental example APIs created with Python Ctypes.
These example APIs enables Python to perform enclave operations in Intel(R) Software Guard Extensions (SGX):
    - Initialize and destroy an enclave.
    - Generate a random byte array using SGX trusted library function (sgx_read_rand).

### How to Build/Execute the Sample Code

- Install Intel(R) SGX SDK for Linux* OS
- Install Ctypes
- export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:\`pwd\`
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
- Execute example Python app:
    $ python PythonApp.py [optional: size of byte array]
- Remember to "make clean" before switching build mode

### Brief Introduction of Each Folder and File

- Enclave: defines the functions running in the enclave
- LibSgxC: defines ecall/ocall functions that communicates to the enclave
- LibSgxPython: python ctypes that wraps the shared library
- PythonApp.py: the example python application

## Sgx_Go

The project demonstrates several fundamental example APIs created with .
These example APIs enables Python to perform enclave operations in Intel(R) Software Guard Extensions (SGX):
    - Initialize and destroy an enclave.
    - Generate a random byte array using SGX trusted library function (sgx_read_rand).

### How to Build/Execute the Sample Code

- Install Intel(R) SGX SDK for Linux* OS
- Install Ctypes
- export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:\`pwd\`
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
- Execute example Python app:
    $ ./GoApp [-len=n]
 - Remember to "make clean" before switching build mode

### Brief Introduction of Each Folder and File

- Enclave: defines the functions running in the enclave
- LibSgxC: defines ecall/ocall functions that communicates to the enclave
- LibSgxGo: cgo that wraps the shared library
- GoApp.go: the example Go application
