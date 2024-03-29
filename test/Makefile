##############################################################################
# build tests per arch
##############################################################################

include bringup-bench/build.mk
include src/build.mk

COMMON_TESTS := atomic fib memset mpu timer \
	bb_ackermann \
	bb_banner \
	bb_boyer-moore-search \
	bb_cipher \
	bb_dhrystone \
	bb_distinctness \
	bb_flood-fill \
	bb_hanoi \
	bb_heapsort \
	bb_mandelbrot \
	bb_mersenne \
	bb_pascal \
	bb_shortest-path \
	bb_sieve \
	bb_totient \


FP_TESTS := float sin
LIBTARGETS := driver

riscv32_TESTS := rvcomp

ALL_TESTS := $(COMMON_TESTS) $($(BLD_TARGET_ARCH_FAMILY)_TESTS)

ifeq ($(BLD_TARGET_FPU32),1)
ALL_TESTS += $(FP_TESTS)
endif

##############################################################################
# flags
##############################################################################

# don't delete some intermediate files
.SECONDARY:

CFLAGS := -O2 -MMD $(BLD_TARGET_CFLAGS) -I$(BLD_TARGET_INCDIR)
INCLUDES := -I$(BLD_HOST_INCDIR) -Ibringup-bench/include
DOBJS :=


all: tests


##############################################################################
# library include rules
##############################################################################

# remove duplicates
LIBTARGETS := $(sort $(LIBTARGETS))

define include_lib

LIB := $(1)
$(1)_INCLUDES :=
$(1)_CSOURCES :=
$(1)_CXXSOURCES :=

include lib/$(1)/build.mk

$(1)_CCSOURCES := $$(filter %.cc,$$($(1)_CXXSOURCES))
$(1)_CPPSOURCES := $$(filter %.cpp,$$($(1)_CXXSOURCES))
$(1)_OBJS := $$($(1)_CSOURCES:%.c=$(BLD_TARGET_OBJDIR)/%.c.o) $$($(1)_CCSOURCES:%.cc=$(BLD_TARGET_OBJDIR)/%.cc.o) $$($(1)_CPPSOURCES:%.cpp=$(BLD_TARGET_OBJDIR)/%.cpp.o)
DOBJS += $$($(1)_OBJS)

endef

$(foreach lib,$(LIBTARGETS),$(eval $(call include_lib,$(lib))))

##############################################################################
# test include rules
##############################################################################

define include_test

$(1)_OBJS := $$($(1)_CSOURCES:%.c=$(BLD_TARGET_OBJDIR)/%.c.o)
DOBJS += $$($(1)_OBJS)

endef

$(foreach test,$(ALL_TESTS),$(eval $(call include_test,$(test))))

##############################################################################
# top level build rules
##############################################################################

$(BLD_TARGET_OBJDIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	@echo " [cc]" $(notdir $<)
	@$(BLD_TARGET_CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -c -o $@ $<


##############################################################################
# library build rules
##############################################################################

define build_lib

lib$(1): $(BLD_TARGET_LIBDIR)/lib$(1).a

$(BLD_TARGET_LIBDIR)/lib$(1).a: $($(1)_OBJS)
	@mkdir -p $$(dir $$@)
	@echo " [ar]" $$(notdir $$@)
	@rm -f $$@
	@$(BLD_TARGET_AR) -c -q $$@ $$^

endef

$(foreach lib,$(LIBTARGETS),$(eval $(call build_lib,$(lib))))


##############################################################################
# test build rules
##############################################################################

TEST_LIBS := \
	$(BLD_TARGET_LIBDIR)/crt0.o \
	$(BLD_TARGET_LIBDIR)/runtime.a \
	$(BLD_TARGET_LIBDIR)/libc.a

define build_test

$(1): $(BLD_TARGET_BINDIR)/$(1)

$(BLD_TARGET_BINDIR)/$(1): $($(1)_OBJS) $(BLD_TARGET_LIBDIR)/libdriver.a
	@mkdir -p $$(dir $$@)
	@echo " [ld]" $$(notdir $$@)
	@$(BLD_TARGET_LD) --image-base=$(BLD_TARGET_IMAGE_BASE) -o $$@ $$^ $(TEST_LIBS)

endef

$(foreach test,$(ALL_TESTS),$(eval $(call build_test,$(test))))


tests: $(ALL_TESTS)


.PHONY: clean
clean:
	@rm -rf $(BLD_TARGET_OBJDIR)


ifneq ($(MAKECMDGOALS),clean)
-include $(DOBJS:.o=.d)
endif