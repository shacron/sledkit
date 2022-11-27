# sledKit build script

# Most user settings are found in config.mk

ROOTDIR := $(PWD)
export SDKDIR := $(ROOTDIR)/sdk

export BLD_HOST_OS := $(shell uname -s)
export BLD_HOST_ARCH = $(shell uname -m)
ifeq ($(BLD_HOST_OS),Darwin)
export BLD_HOST_DIR := $(BLD_HOST_OS)
else
export BLD_HOST_DIR := $(BLD_HOST_OS)-$(BLD_HOST_ARCH)
endif

HOST_ROOT := $(SDKDIR)/host/$(BLD_HOST_DIR)

export BLD_HOST_BINDIR := $(HOST_ROOT)/bin
export BLD_HOST_LIBDIR := $(HOST_ROOT)/lib
export BLD_HOST_INCDIR := $(SDKDIR)/include
export BLD_RUNTIME_ROOT := $(ROOTDIR)/runtime

include config.mk

TARGET_ROOT := $(SDKDIR)/target/$(BLD_TARGET_ARCH)
export BLD_TARGET_LIBDIR := $(TARGET_ROOT)/lib
export BLD_TARGET_BINDIR := $(TARGET_ROOT)/bin
export BLD_TARGET_INCDIR := $(SDKDIR)/target/include

export MAKE
export BLD_TARGET_ISA
export BLD_TARGET_ARCH
export BLD_TARGET_IMAGE_BASE
export BLD_LLVM_VERSION
export BLD_HOST_CC
export BLD_HOST_CXX
export BLD_HOST_AS
export BLD_HOST_LD
export BLD_HOST_AR
export BLD_TARGET_CC
export BLD_TARGET_CXX
export BLD_TARGET_AS
export BLD_TARGET_LD
export BLD_TARGET_AR
export BLD_BASEDIR
export BLD_ARCHIVEDIR
export BLD_TOOLCHAINDIR
export BLD_TOOLCHAIN_HOST_ROOT
export BLD_TOOLCHAIN_BINDIR

ifeq ($(BLD_TARGET_TRIPLE),)

ifneq ($(findstring rv32,$(BLD_TARGET_ARCH)),)
TARGET_TRIPLE_ARCH := riscv32
endif

ifneq ($(findstring rv64,$(BLD_TARGET_ARCH)),)
TARGET_TRIPLE_ARCH := riscv64
endif

BLD_TARGET_TRIPLE := $(TARGET_TRIPLE_ARCH)-linux-none
BLD_TARGET_CFLAGS := -target $(BLD_TARGET_TRIPLE) -march=$(BLD_TARGET_ARCH)

endif # BLD_TARGET_TRIPLE

export BLD_TARGET_TRIPLE
export BLD_TARGET_CFLAGS

SLEDDIR ?= sled
LIBCDIR ?= libc
TESTDIR := test
JOBS ?= $(shell getconf _NPROCESSORS_ONLN)

ALL_TARGETS := $(wildcard sled libc monitor runtime)

all: tests

.PHONY: sled
sled:
	@$(MAKE) -s -C $(SLEDDIR) install BLD_HOST_OBJDIR=$(HOST_OBJDIR)/$@

.PHONY: libc
libc:
	@$(MAKE) -s -C $(LIBCDIR) install BLD_BASEDIR=$(TARGET_OBJDIR)/$@

.PHONY: runtime
runtime:
	@$(MAKE) -s -C $@ BLD_TARGET_OBJDIR=$(TARGET_OBJDIR)/$@

.PHONY: monitor
monitor: runtime libc
	@$(MAKE) -s -C $@ BLD_TARGET_OBJDIR=$(TARGET_OBJDIR)/$@

.PHONY: tests
tests: $(ALL_TARGETS)
	@$(MAKE) -s -C $(TESTDIR) BLD_TARGET_OBJDIR=$(TARGET_OBJDIR)/$@

#####################################################################
# toolchain build - only needed at bootstrap
#####################################################################

.PHONY: toolchain
toolchain:
	@$(MAKE) -s -j $(JOBS) -f tools.mk BLD_HOST_OBJDIR=$(HOST_OBJDIR)/llvm


.PHONY: clean
clean:
	@rm -rf $(BLD_BASEDIR) $(SDKDIR)/target $(SDKDIR)/host

# warning: this will require rebuilding the toolchain
.PHONY: reallyclean
reallyclean:
	@rm -rf $(BLD_BASEDIR) $(SDKDIR) $(BLD_RUNTIME_ROOT)/builtins

