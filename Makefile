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
export BLD_TARGET_NM
export BLD_TARGET_OBJCOPY
export BLD_TARGET_OBJDUMP
export BLD_BASEDIR
export BLD_ARCHIVEDIR
export BLD_TOOLCHAINDIR
export BLD_TOOLCHAIN_HOST_ROOT
export BLD_TOOLCHAIN_BINDIR
export BLD_HOST_UNIVERSAL
export BLD_HOST_USE_SANITIZERS

ifeq ($(BLD_TARGET_TRIPLE),)

ifneq ($(findstring rv32,$(BLD_TARGET_ARCH)),)
export BLD_TARGET_ARCH_FAMILY := riscv32
X_TRIM_ARCH := $(subst rv32,,$(BLD_TARGET_ARCH))
endif

ifneq ($(findstring rv64,$(BLD_TARGET_ARCH)),)
export BLD_TARGET_ARCH_FAMILY := riscv64
X_TRIM_ARCH := $(subst rv64,,$(BLD_TARGET_ARCH))
endif

# derive whether floating point is supported
# this probably breaks with the fancier Z extensions, but it will do for now.
ifeq ($(findstring $(BLD_TARGET_ARCH_FAMILY),riscv32 riscv64),$(BLD_TARGET_ARCH_FAMILY))
ifeq ($(findstring f,$(X_TRIM_ARCH)),f)
export BLD_TARGET_FPU32 := 1
endif
ifeq ($(findstring f,$(X_TRIM_ARCH)),d)
export BLD_TARGET_FPU64 := 1
endif
endif

BLD_TARGET_TRIPLE := $(BLD_TARGET_ARCH_FAMILY)-linux-none
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

.PHONY: headers
headers:
	@$(MAKE) -s -C $(SLEDDIR) install_headers BLD_HOST_OBJDIR=$(HOST_OBJDIR)/$@
	@$(MAKE) -s -C $(LIBCDIR) install_headers BLD_HOST_OBJDIR=$(HOST_OBJDIR)/$@

.PHONY: sled
sled:
	@$(MAKE) -s -C $(SLEDDIR) install BLD_HOST_OBJDIR=$(HOST_OBJDIR)/$@

.PHONY: libc
libc:
	@$(MAKE) -s -C $(LIBCDIR) install BLD_BASEDIR=$(TARGET_OBJDIR)/$@

.PHONY: runtime
runtime: headers
	@$(MAKE) -s -C $@ BLD_TARGET_OBJDIR=$(TARGET_OBJDIR)/$@

.PHONY: monitor
monitor: headers runtime libc
	@$(MAKE) -s -C $@ BLD_TARGET_OBJDIR=$(TARGET_OBJDIR)/$@

.PHONY: tests
tests: headers $(ALL_TARGETS)
	@$(MAKE) -s -C $(TESTDIR) BLD_TARGET_OBJDIR=$(TARGET_OBJDIR)/$@

#####################################################################
# python bindings build
# python bindings require a special build that disables sanitizers
#####################################################################

define build_py_bindings
	@echo "If binding build failed, you may need to clean old build results."
	@echo "Python bindings require disabling sanitizers that are normally enabled."
	@$(MAKE) -s BLD_HOST_UNIVERSAL=1 BLD_HOST_USE_SANITIZERS=0
	@python3 bindings/python/setup.py build_ext -q -I $(BLD_HOST_INCDIR) -O $(BLD_HOST_LIBDIR)/libsled.a \
		--build-lib=$(BLD_HOST_LIBDIR) --build-temp=$(HOST_OBJDIR) -j $(JOBS)
	@echo "set PYTHONPATH=$(BLD_HOST_LIBDIR) to use this extension, and 'import psled'"

endef

.PHONY: py
py:
	$(call build_py_bindings)

.PHONY: python_bindings
python_bindings: clean
	$(call build_py_bindings)

#####################################################################
# toolchain build - only needed at bootstrap
#####################################################################

.PHONY: toolchain
toolchain:
	@$(MAKE) -s -j $(JOBS) -f tools.mk BLD_HOST_OBJDIR=$(HOST_OBJDIR)/llvm


.PHONY: clean
clean:
	@rm -rf $(BLD_BASEDIR) $(SDKDIR)/target $(SDKDIR)/host $(SDKDIR)/include

# warning: this will require rebuilding the toolchain
.PHONY: reallyclean
reallyclean:
	@rm -rf $(BLD_BASEDIR) $(SDKDIR)

