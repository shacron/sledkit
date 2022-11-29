#####################################################################
# toolchain build
# building this toolchain requires installing the following tools:
# macos: xcode and commandline tools
# linux: clang, lld
# all: cmake
#####################################################################

LLVM_SOURCE  := llvm-project-$(BLD_LLVM_VERSION).src
LLVM_ARCHIVE := $(LLVM_SOURCE).tar.xz
LLVM_URL     := https://github.com/llvm/llvm-project/releases/download/llvmorg-$(BLD_LLVM_VERSION)/$(LLVM_ARCHIVE)
LLVM_ARCHIVE_PATH := $(BLD_ARCHIVEDIR)/$(LLVM_ARCHIVE)
LLVM_SOURCE_DIR := $(BLD_HOST_OBJDIR)/$(LLVM_SOURCE)
LLVM_BUILD_DIR := $(BLD_HOST_OBJDIR)/llvm-build
# LLVM_RUNTIME_DIR := $(ROOTDIR)/runtime

ifeq ($(BLD_HOST_LD),ld.lld)
# Clang does not like '-fuse-ld=ld.lld'
LLVM_LD := lld
else
LLVM_LD := $(BLD_HOST_LD)
endif

# AArch64;AMDGPU;ARM;AVR;BPF;Hexagon;Lanai;Mips;MSP430;NVPTX;PowerPC;RISCV;Sparc;SystemZ;VE;WebAssembly;X86;XCore

BUILDOPTS := \
	-DLLVM_TARGETS_TO_BUILD="AArch64;ARM;RISCV" \
	-DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra;lld" \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_C_COMPILER=$(BLD_HOST_CC) \
	-DCMAKE_CXX_COMPILER=$(BLD_HOST_CXX) \
	-DLLVM_USE_LINKER=$(LLVM_LD) \
	-DCMAKE_INSTALL_PREFIX=$(BLD_TOOLCHAIN_HOST_ROOT)

all: toolchain

# download
$(LLVM_ARCHIVE_PATH):
	@mkdir -p $(dir $@)
	@echo "[curl] " $@
	@curl --create-dirs -L --output $(LLVM_ARCHIVE_PATH) $(LLVM_URL)

# extract
$(LLVM_SOURCE_DIR): $(LLVM_ARCHIVE_PATH)
	@mkdir -p $(dir $@)
	@echo "[tar]" $^
	@tar -xf $(LLVM_ARCHIVE_PATH) -C $(dir $@)

# build
toolchain: $(LLVM_SOURCE_DIR)
	@rm -rf $(LLVM_BUILD_DIR) $(BLD_RUNTIME_ROOT)/builtins
	@mkdir -p $(LLVM_BUILD_DIR) $(BLD_RUNTIME_ROOT)
	@cp -r $(LLVM_SOURCE_DIR)/compiler-rt/lib/builtins $(BLD_RUNTIME_ROOT)
	@cd $(LLVM_BUILD_DIR) && cmake -G "Unix Makefiles" "$(LLVM_SOURCE_DIR)/llvm" $(BUILDOPTS)
	@$(MAKE) -C $(LLVM_BUILD_DIR)
	@$(MAKE) -C $(LLVM_BUILD_DIR) install
