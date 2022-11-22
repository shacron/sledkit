##############################################################################
# build tests per arch
##############################################################################

include src/build.mk

COMMON_TESTS := fib
LIBTARGETS := driver

riscv32_TESTS := rvcomp

ALL_TESTS := $(COMMON_TESTS) $(riscv32_TESTS)


##############################################################################
# flags
##############################################################################

# don't delete some intermediate files
.SECONDARY:

CFLAGS := -O2 -MMD $(BLD_TARGET_CFLAGS) -I$(BLD_TARGET_INCDIR)
INCLUDES := -I$(BLD_HOST_INCDIR)
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
# crt0 build rules
##############################################################################

$(BLD_TARGET_LIBDIR)/crt0.o: $(BLD_TARGET_OBJDIR)/crt0.o
	@cp $< $@

$(BLD_TARGET_OBJDIR)/crt0.o: arch/$(BLD_TARGET_ISA)/crt0.S
	@mkdir -p $(dir $@)
	@echo " [as]" $(notdir $@)
	@$(BLD_TARGET_AS) $(CFLAGS) -c -o $@ $<


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

define build_test

$(1): $(BLD_TARGET_BINDIR)/$(1)

$(BLD_TARGET_BINDIR)/$(1): $($(1)_OBJS) $(BLD_TARGET_LIBDIR)/crt0.o $(BLD_TARGET_LIBDIR)/libdriver.a
	@mkdir -p $$(dir $$@)
	@echo " [ld]" $$(notdir $$@)
	@$(BLD_TARGET_LD) --image-base=$(BLD_TARGET_IMAGE_BASE) -o $$@ $$^ $(BLD_TARGET_LIBDIR)/runtime.a $(BLD_TARGET_LIBDIR)/libc.a

endef

$(foreach test,$(ALL_TESTS),$(eval $(call build_test,$(test))))


tests: $(ALL_TESTS)


.PHONY: clean
clean:
	@rm -rf $(BLD_TARGET_OBJDIR)


ifneq ($(MAKECMDGOALS),clean)
-include $(DOBJS:.o=.d)
endif