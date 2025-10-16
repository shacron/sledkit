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
    git clone https://github.com/shacron/sled.git
    git clone https://github.com/shacron/carmel.git libc
    export JOBS=`getconf _NPROCESSORS_ONLN`
    make toolchain
    make -j $JOBS
    ./sdk/host/<os>/bin/sled sdk/target/rv32im/bin/fib


## Detailed Setup

### Clone this project

    git clone https://github.com/shacron/sledkit.git
    cd sledkit

### Build toolchain

    make toolchain

This will download and build the LLVM cross-compiler and binutils. This will take some time.

### Clone sled

    git clone https://github.com/shacron/sled.git
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

Code for the compiler runtime from the LLVM project (`compiler-rt`) is installed in `runtime/builtin`. This code is updated when the toolchain is built. Code for the C runtime is in `runtime/arch/<arch>/crt0.S`.

    make -j $JOBS runtime

This will install the runtime in `sdk/target/<target>/lib/runtime.a` and crt0 `sdk/target/<target>/lib/crt0.o`

Libc is optional, but useful. Having printf() connected to the UART device is convenient. You may use any libc implementation that supports standalone targets. This project has been tested with `carmel` embedded libc, which should be the easiest to use.

    git clone https://github.com/shacron/carmel.git libc
    make -j $JOBS libc

This will build and install libc.a in `sdk/target/<target>/lib/`

## Setting The Target Architecture

The default target as well as other parameters are defines in `config.mk`. You may edit this file directly to change them. You can also change the target by overriding these variable in your environment or on the command line.

Example:

    make -j $JOBS BLD_TARGET_ARCH=rv64imc

Additional parameters, such as CFLAGS, may be required depending on the target.

## ~~Building Python Binding~~

**PYTHON BINDINGS ARE EXTREMELY OUT OF DATE**

_The Python bindings have not kept up with changes in the code and are currently a low priority. They will likely be resurrected in the future, but they are currently too difficult to maintain with a rapidly changing API._

A Python language extension can be built using the following command:

    make -j $JOBS python_bindings

This will build a shared object `sdk/host/<os-arch>/lib/psled.cpython-<version>.so` loadable by your system's Python interpreter. To load it you must add this path to your `PYTHONPATH`. For example:

    export PYTHONPATH=/path/to/sdk/host/<os-arch>/lib

Then launch `python3` or import it into your scripts in your scripts

### Example

    import psled

    def main():
        m = psled.machine()
        m.add_mem(0x10000, (5 * 1024 * 1024))
        m.add_dev(128, 0x5000000, "uart0")
        id = m.add_core(2, 0, 0, 0)
        m.load_core(id, "sdk/target/rv32im/bin/fib")
        c = m.get_core(id)
        c.step(100000)
        print("done")

    if (__name__ == "__main__"):
        main()

the `dir()` command will show available functions

    >>> dir(psled)

### ~~Rebuilding Python Bindings~~

**PYTHON BINDINGS ARE EXTREMELY OUT OF DATE**

If you are making changes to sled or other components, you may need to rebuild bindings frequently. Unfortunately, Python bindings require two build options that differ from the standard options. One, they require disabling sanitizers linked into sled, unless your Python was built with the sanitizers enabled (unlikely). Two, on macOS they expect a universal (multi-architecture) build. This is why Python bindings are not built by default.

The `python_bindings` target does a clean build to guarantee that the above requirements are met. There is a second target, `py`, which builds the sdk and its dependencies without cleaning. If you frequently need to rebuild the Python bindings, you can use this after your first invocation of `make python_bindings`.

### Python Extension Errors

You may encounter the following errors with Python bindings:

When importing the extension, you may see

    >>> import psled
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    ImportError: dlopen(/path/to/sdk/host/Darwin/lib/psled.cpython-39-darwin.so, 0x0002): symbol not found in flat namespace '___asan_option_detect_stack_use_after_return'

If you encounter this, you have linked the extension against a sled build with address sanitizer enabled. `make clean` and rebuild with `make python_bindings`.

If you encounter this error for a symbol that does not look like a sanitizer symbol (`__asan` or similar), it is likely that the extension did not link correctly. Check the link step results.

On macOS you may see the following warning. It is harmless and can be ignored.

    ld: warning: object file (../../sdk/host/Darwin/lib/libsled.a(intc.c.o)) was built for newer macOS version (13.0) than being linked (11.0)

However, the following warning is actually an error. It indicates that the `libsled.a` archive is old (created with `ar` instead of `libtool`) or built for a single architecture, and cannot be used for universal builds. Cleaning and rebuilding via `make python_bindings` should fix this.

    ld: warning: ignoring file ../../sdk/host/Darwin/lib/libsled.a, building for macOS-x86_64 but attempting to link with file built for macOS-arm64


## License

sledKit is Copyright (c) 2022-2025, Shac Ron and The Sled Project

Unless otherwise stated, all code is licensed under the MIT License. The short version is that you can use this code for any purpose, but should retain the copyright notice in the source.

Compiler-RT Runtime builtins in `runtime/builtins/` are copyright the LLVM Project and available under the Apache-2.0 WITH LLVM-exception license. The code originates from LLVM: https://llvm.org

RISCV conformance test code is copyright (c) 2019, Imperas Software Ltd. Copyright notice is contained in the relevant source files.

