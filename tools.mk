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

BUILDOPTS := \
	-DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra;lld" \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_C_COMPILER=$(BLD_HOST_CC) \
	-DCMAKE_CXX_COMPILER=$(BLD_HOST_CXX) \
	-DLLVM_USE_LINKER=$(BLD_HOST_LD) \
	-DCMAKE_INSTALL_PREFIX=$(BLD_TOOLCHAIN_HOST_ROOT)

all: toolchain

# download
$(LLVM_ARCHIVE_PATH):
	@mkdir -p $(dir $@)
	wget $(LLVM_URL) -P $(dir $@)

# extract
$(LLVM_SOURCE_DIR): $(LLVM_ARCHIVE_PATH)
	@mkdir -p $(dir $@)
	tar -xzf $(LLVM_ARCHIVE_PATH) -C $(dir $@)

# build
toolchain: $(LLVM_SOURCE_DIR)
	@rm -rf $(LLVM_BUILD_DIR) $(BLD_RUNTIME_ROOT)/builtins
	@mkdir -p $(LLVM_BUILD_DIR) $(BLD_RUNTIME_ROOT)
	@cp -r $(LLVM_SOURCE_DIR)/compiler-rt/lib/builtins $(BLD_RUNTIME_ROOT)
	cd $(LLVM_BUILD_DIR) && cmake -G "Unix Makefiles" "$(LLVM_SOURCE_DIR)/llvm" $(BUILDOPTS)
	$(MAKE) -C $(LLVM_BUILD_DIR)
	$(MAKE) -C $(LLVM_BUILD_DIR) install
