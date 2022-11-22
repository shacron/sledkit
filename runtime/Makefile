###################################################################
# build compiler rt - target-specific runtime
####################################################################

SOURCEDIR := $(BLD_RUNTIME_ROOT)

include clang_rt.mk

INCLUDES := -I$(BLD_TARGET_INCDIR)
DEFINES :=
CFLAGS := -O2 -MMD $(BLD_TARGET_CFLAGS)

ALL_SOURCES := $(BUILTIN_BASE) $(BUILTIN_$(BLD_TARGET_ISA)) $(BUILTIN_$(BLD_TARGET_ARCH))

ALL_OBJS := $(ALL_SOURCES:$(SOURCEDIR)/%.c=$(BLD_TARGET_OBJDIR)/%.c.o)
ALL_OBJS := $(ALL_OBJS:$(SOURCEDIR)/%.S=$(BLD_TARGET_OBJDIR)/%.S.o)

runtime: $(BLD_TARGET_LIBDIR)/runtime.a

$(BLD_TARGET_LIBDIR)/runtime.a: $(ALL_OBJS)
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
