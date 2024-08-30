###################################################################
# build compiler rt - target-specific runtime
####################################################################

SOURCEDIR := $(BLD_RUNTIME_ROOT)

include clang_rt.mk

INCLUDES := -I$(BLD_TARGET_INCDIR)
DEFINES :=
CFLAGS := -O2 -MMD $(BLD_TARGET_CFLAGS)

# This line likely needs fixing for non-riscv targets
RUNTIME_SOURCES := $(BUILTIN_$(BLD_TARGET_ARCH_FAMILY)_SOURCES)

ifneq ($(findstring riscv,$(BLD_TARGET_ARCH_FAMILY)),)
  CFLAGS += -fforce-enable-int128
endif

RUNTIME_OBJS := $(RUNTIME_SOURCES:$(SOURCEDIR)/%.c=$(BLD_TARGET_OBJDIR)/%.c.o)
RUNTIME_OBJS := $(RUNTIME_OBJS:$(SOURCEDIR)/%.S=$(BLD_TARGET_OBJDIR)/%.S.o)

all: runtime crt

runtime: $(BLD_TARGET_LIBDIR)/runtime.a

$(BLD_TARGET_LIBDIR)/runtime.a: $(RUNTIME_OBJS)
	@echo " [ar]" $(notdir $@)
	@mkdir -p $(dir $@)
	@rm -f $@
	@$(BLD_TARGET_AR) -c -q $@ $^

$(BLD_TARGET_OBJDIR)/%.c.o: $(SOURCEDIR)/%.c
	@mkdir -p $(dir $@)
	@echo " [cc]" $(notdir $<)
	@$(BLD_TARGET_CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -c -o $@ $<

$(BLD_TARGET_OBJDIR)/%.S.o: $(SOURCEDIR)/%.S
	@mkdir -p $(dir $@)
	@echo " [as]" $(notdir $<)
	@$(BLD_TARGET_AS) $(CFLAGS) $(INCLUDES) $(DEFINES) -c -o $@ $<

##############################################################################
# crt0 build rules
##############################################################################

crt: $(BLD_TARGET_LIBDIR)/crt0.o

$(BLD_TARGET_LIBDIR)/crt0.o: $(BLD_TARGET_OBJDIR)/crt0.o
	@cp $< $@

$(BLD_TARGET_OBJDIR)/crt0.o: arch/$(BLD_TARGET_ISA)/crt0.S
	@mkdir -p $(dir $@)
	@echo " [as]" $(notdir $@)
	@$(BLD_TARGET_AS) $(CFLAGS) -c -o $@ $<
