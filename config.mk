# User-defined setting for building sledKit
# Most options can be overridden in this file, via the environment, or
# on the commandline invocation of 'make'

# directory in which intermediate build products will be created
BLD_BASEDIR ?= $(ROOTDIR)/build
HOST_OBJDIR ?= $(BLD_BASEDIR)/host

BLD_TARGET_ISA ?= riscv
BLD_TARGET_ARCH ?= rv32im

TARGET_OBJDIR ?= $(BLD_BASEDIR)/$(BLD_TARGET_ARCH)

# if BLD_TARGET_TRIPLE is undefined, it and BLD_TARGET_CFLAGS will be guessed
# based on the arch
BLD_TARGET_TRIPLE ?=
BLD_TARGET_CFLAGS ?=

# address at which to link target binaries
BLD_TARGET_IMAGE_BASE ?= 0x10000

# version of llvm and clang to use
# leave blank if using a different toolchain
BLD_LLVM_VERSION ?= 15.0.6

MAKE ?= make

# host tools
# on linux hosts, using gcc and ld is possible. However, building the target
# tools will be significantly faster with clang and lld.
BLD_HOST_CC  ?= clang
BLD_HOST_CXX ?= clang++
BLD_HOST_AS  ?= clang
ifeq ($(BLD_HOST_OS),Darwin)
BLD_HOST_LD  ?= ld
# build multi-architecture host binaries
BLD_HOST_UNIVERSAL ?= 0
else
BLD_HOST_LD  ?= ld.lld
BLD_HOST_UNIVERSAL := 0
endif
BLD_HOST_AR  ?= ar

# use sanitizer tools to catch runtime errors
BLD_HOST_USE_SANITIZERS ?= 1

# directory in which the toolchain is installed
BLD_TOOLCHAINDIR        ?= $(SDKDIR)/tools
BLD_TOOLCHAIN_HOST_ROOT ?= $(BLD_TOOLCHAINDIR)/$(BLD_HOST_DIR)
BLD_TOOLCHAIN_BINDIR    ?= $(BLD_TOOLCHAIN_HOST_ROOT)/bin

# target tools
BLD_TARGET_CC  ?= $(BLD_TOOLCHAIN_BINDIR)/clang
BLD_TARGET_CXX ?= $(BLD_TOOLCHAIN_BINDIR)/clang++
BLD_TARGET_AS  ?= $(BLD_TOOLCHAIN_BINDIR)/clang
BLD_TARGET_LD  ?= $(BLD_TOOLCHAIN_BINDIR)/ld.lld
BLD_TARGET_AR  ?= $(BLD_TOOLCHAIN_BINDIR)/llvm-ar
BLD_TARGET_NM  ?= $(BLD_TOOLCHAIN_BINDIR)/llvm-nm
BLD_TARGET_OBJCOPY ?= $(BLD_TOOLCHAIN_BINDIR)/llvm-objcopy
BLD_TARGET_OBJDUMP ?= $(BLD_TOOLCHAIN_BINDIR)/llvm-objcopy

BLD_ARCHIVEDIR ?= $(ROOTDIR)/archive

