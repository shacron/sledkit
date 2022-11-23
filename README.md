# sledKit
SDK for sled emulator

This project provides a toolchain and runtime environment for building executables to run on the sled emulator (https://github.com/shacron/sled)

## Requirements

This code should run and build on macOS and Linux systems.

### macOS Requirements

* Xcode and the xcode command line tools
* `cmake`

`cmake` can be installed via homebrew or other means.

    brew install cmake


### Linux Requirements

* `make`
* `clang`
* `lld`
* `cmake`

All of these can be installed via your package manager.

    sudo apt install make clang lld cmake


## Quick Setup With No Reading

Read more below to understand what these steps are doing.

    git clone https://github.com/shacron/sledkit.git
    cd sledkit
    git clone [sled]
    git clone https://github.com/shacron/carmel.git libc
    export JOBS=`getconf _NPROCESSORS_ONLN`
    make toolchain
    make -j $JOBS
    ./sdk/host/Darwin/bin/sled sdk/target/rv32im/bin/fib


## Detailed Setup

### Clone this project

    git clone https://github.com/shacron/sledkit.git
    cd sledkit

### Build toolchain

    make toolchain

This will download and build the LLVM cross-compiler and binutils. This will take some time.

### Clone sled

    git clone ...
    export JOBS=`getconf _NPROCESSORS_ONLN`
    make -j $JOBS sled

This will clone the sled repository to sledkit/sled and build it. The resultant binary will be in `./sdk/host/<os>/bin/sled` and the sled static library `libsled.a` will be in the corresponding lib directory. See the `sled` README for details on using these.

This is the minimum required to cross compile executables. However, you will probably want more than that to bootstrap yourself and to run the tests. Install the runtime support for this.

### Runtime

The runtime is made of three components

1. The compiler runtime support library (`runtime.a`)
1. The C runtime (`crt0.o`)
1. The (optional) libc standard library (`libc.a`)

All projects below will be compiled for the target architecture. See "Setting The Target Architecture" for choosing this.

Code for the compiler runtime was installed from the LLVM project (`compiler-rt`) when the toolchain is built. If you skipped this step you will need to provide your own runtime.

    make -j $JOBS runtime

This will install the runtime in `sdk/target/<target>/lib/runtime.a`

The C runtime is built and installed as part of the test software. See "tests" below. TODO: move crt0 out.

Libc is optional, but useful. Having printf() connected to the UART device is convenient. You may use any libc implementation that supports standalone targets. This project has been tested with `carmel` embedded libc, which should be the easiest to use.

    git clone https://github.com/shacron/carmel.git libc
    make -j $JOBS libc

This will build and install libc.a in `sdk/target/<target>/lib/`

## Setting The Target Architecture

The default target as well as other parameters are defines in `config.mk`. You may edit this file directly to change them. You can also change the target by overriding these variable in your environment or on the command line.

Example:

    make -j $JOBS BLD_TARGET_ARCH=rv64imc

Additional parameters may be required, such as CFLAGS, depending on the target.

## License

The code is licensed under the MIT License. The short version that you can use this code for any purpose, but should retain the copyright notice in the source.

All code is copyright 2022, Shac Ron unless otherwise specified.

RISCV conformance test code is copyright (c) 2019, Imperas Software Ltd. Copyright notice is contained in the relevant source files.

