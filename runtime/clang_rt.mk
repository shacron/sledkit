BUILTINDIR := $(SOURCEDIR)/builtins

BUILTIN_BASE := \
	$(BUILTINDIR)/absvdi2.c \
	$(BUILTINDIR)/absvsi2.c \
	$(BUILTINDIR)/absvti2.c \
	$(BUILTINDIR)/adddf3.c \
	$(BUILTINDIR)/addsf3.c \
	$(BUILTINDIR)/addtf3.c \
	$(BUILTINDIR)/addvdi3.c \
	$(BUILTINDIR)/addvsi3.c \
	$(BUILTINDIR)/addvti3.c \
	$(BUILTINDIR)/ashldi3.c \
	$(BUILTINDIR)/ashlti3.c \
	$(BUILTINDIR)/ashrdi3.c \
	$(BUILTINDIR)/ashrti3.c \
	$(BUILTINDIR)/bswapdi2.c \
	$(BUILTINDIR)/bswapsi2.c \
	$(BUILTINDIR)/clzdi2.c \
	$(BUILTINDIR)/clzsi2.c \
	$(BUILTINDIR)/clzti2.c \
	$(BUILTINDIR)/cmpdi2.c \
	$(BUILTINDIR)/cmpti2.c \
	$(BUILTINDIR)/comparedf2.c \
	$(BUILTINDIR)/comparesf2.c \
	$(BUILTINDIR)/comparetf2.c \
	$(BUILTINDIR)/cpu_model.c \
	$(BUILTINDIR)/ctzdi2.c \
	$(BUILTINDIR)/ctzsi2.c \
	$(BUILTINDIR)/ctzti2.c \
	$(BUILTINDIR)/divdc3.c \
	$(BUILTINDIR)/divdf3.c \
	$(BUILTINDIR)/divdi3.c \
	$(BUILTINDIR)/divmoddi4.c \
	$(BUILTINDIR)/divmodsi4.c \
	$(BUILTINDIR)/divmodti4.c \
	$(BUILTINDIR)/divsc3.c \
	$(BUILTINDIR)/divsf3.c \
	$(BUILTINDIR)/divsi3.c \
	$(BUILTINDIR)/divtc3.c \
	$(BUILTINDIR)/divtf3.c \
	$(BUILTINDIR)/divti3.c \
	$(BUILTINDIR)/divxc3.c \
	$(BUILTINDIR)/extenddftf2.c \
	$(BUILTINDIR)/extendhfsf2.c \
	$(BUILTINDIR)/extendhftf2.c \
	$(BUILTINDIR)/extendsfdf2.c \
	$(BUILTINDIR)/extendsftf2.c \
	$(BUILTINDIR)/ffsdi2.c \
	$(BUILTINDIR)/ffssi2.c \
	$(BUILTINDIR)/ffsti2.c \
	$(BUILTINDIR)/fixdfdi.c \
	$(BUILTINDIR)/fixdfsi.c \
	$(BUILTINDIR)/fixdfti.c \
	$(BUILTINDIR)/fixsfdi.c \
	$(BUILTINDIR)/fixsfsi.c \
	$(BUILTINDIR)/fixsfti.c \
	$(BUILTINDIR)/fixtfdi.c \
	$(BUILTINDIR)/fixtfsi.c \
	$(BUILTINDIR)/fixtfti.c \
	$(BUILTINDIR)/fixunsdfdi.c \
	$(BUILTINDIR)/fixunsdfsi.c \
	$(BUILTINDIR)/fixunsdfti.c \
	$(BUILTINDIR)/fixunssfdi.c \
	$(BUILTINDIR)/fixunssfsi.c \
	$(BUILTINDIR)/fixunssfti.c \
	$(BUILTINDIR)/fixunstfdi.c \
	$(BUILTINDIR)/fixunstfsi.c \
	$(BUILTINDIR)/fixunstfti.c \
	$(BUILTINDIR)/fixunsxfdi.c \
	$(BUILTINDIR)/fixunsxfsi.c \
	$(BUILTINDIR)/fixunsxfti.c \
	$(BUILTINDIR)/fixxfdi.c \
	$(BUILTINDIR)/fixxfti.c \
	$(BUILTINDIR)/floatdidf.c \
	$(BUILTINDIR)/floatdisf.c \
	$(BUILTINDIR)/floatditf.c \
	$(BUILTINDIR)/floatdixf.c \
	$(BUILTINDIR)/floatsidf.c \
	$(BUILTINDIR)/floatsisf.c \
	$(BUILTINDIR)/floatsitf.c \
	$(BUILTINDIR)/floattidf.c \
	$(BUILTINDIR)/floattisf.c \
	$(BUILTINDIR)/floattitf.c \
	$(BUILTINDIR)/floattixf.c \
	$(BUILTINDIR)/floatundidf.c \
	$(BUILTINDIR)/floatundisf.c \
	$(BUILTINDIR)/floatunditf.c \
	$(BUILTINDIR)/floatundixf.c \
	$(BUILTINDIR)/floatunsidf.c \
	$(BUILTINDIR)/floatunsisf.c \
	$(BUILTINDIR)/floatunsitf.c \
	$(BUILTINDIR)/floatuntidf.c \
	$(BUILTINDIR)/floatuntisf.c \
	$(BUILTINDIR)/floatuntitf.c \
	$(BUILTINDIR)/floatuntixf.c \
	$(BUILTINDIR)/fp_mode.c \
	$(BUILTINDIR)/gcc_personality_v0.c \
	$(BUILTINDIR)/int_util.c \
	$(BUILTINDIR)/lshrdi3.c \
	$(BUILTINDIR)/lshrti3.c \
	$(BUILTINDIR)/moddi3.c \
	$(BUILTINDIR)/modsi3.c \
	$(BUILTINDIR)/modti3.c \
	$(BUILTINDIR)/muldc3.c \
	$(BUILTINDIR)/muldf3.c \
	$(BUILTINDIR)/mulodi4.c \
	$(BUILTINDIR)/mulosi4.c \
	$(BUILTINDIR)/muloti4.c \
	$(BUILTINDIR)/mulsc3.c \
	$(BUILTINDIR)/mulsf3.c \
	$(BUILTINDIR)/multc3.c \
	$(BUILTINDIR)/multf3.c \
	$(BUILTINDIR)/multi3.c \
	$(BUILTINDIR)/mulvdi3.c \
	$(BUILTINDIR)/mulvsi3.c \
	$(BUILTINDIR)/mulvti3.c \
	$(BUILTINDIR)/mulxc3.c \
	$(BUILTINDIR)/negdf2.c \
	$(BUILTINDIR)/negdi2.c \
	$(BUILTINDIR)/negsf2.c \
	$(BUILTINDIR)/negti2.c \
	$(BUILTINDIR)/negvdi2.c \
	$(BUILTINDIR)/negvsi2.c \
	$(BUILTINDIR)/negvti2.c \
	$(BUILTINDIR)/os_version_check.c \
	$(BUILTINDIR)/paritydi2.c \
	$(BUILTINDIR)/paritysi2.c \
	$(BUILTINDIR)/parityti2.c \
	$(BUILTINDIR)/popcountdi2.c \
	$(BUILTINDIR)/popcountsi2.c \
	$(BUILTINDIR)/popcountti2.c \
	$(BUILTINDIR)/powidf2.c \
	$(BUILTINDIR)/powisf2.c \
	$(BUILTINDIR)/powitf2.c \
	$(BUILTINDIR)/powixf2.c \
	$(BUILTINDIR)/subdf3.c \
	$(BUILTINDIR)/subsf3.c \
	$(BUILTINDIR)/subtf3.c \
	$(BUILTINDIR)/subvdi3.c \
	$(BUILTINDIR)/subvsi3.c \
	$(BUILTINDIR)/subvti3.c \
	$(BUILTINDIR)/trampoline_setup.c \
	$(BUILTINDIR)/truncdfhf2.c \
	$(BUILTINDIR)/truncdfsf2.c \
	$(BUILTINDIR)/truncsfhf2.c \
	$(BUILTINDIR)/trunctfhf2.c \
	$(BUILTINDIR)/trunctfsf2.c \
	$(BUILTINDIR)/ucmpdi2.c \
	$(BUILTINDIR)/ucmpti2.c \
	$(BUILTINDIR)/udivdi3.c \
	$(BUILTINDIR)/udivmoddi4.c \
	$(BUILTINDIR)/udivmodsi4.c \
	$(BUILTINDIR)/udivmodti4.c \
	$(BUILTINDIR)/udivsi3.c \
	$(BUILTINDIR)/udivti3.c \
	$(BUILTINDIR)/umoddi3.c \
	$(BUILTINDIR)/umodsi3.c \
	$(BUILTINDIR)/umodti3.c \


BUILTIN_ATOMIC := \
	$(BUILTINDIR)/atomic.c \
	$(BUILTINDIR)/atomic_flag_clear.c \
	$(BUILTINDIR)/atomic_flag_clear_explicit.c \
	$(BUILTINDIR)/atomic_flag_test_and_set.c \
	$(BUILTINDIR)/atomic_flag_test_and_set_explicit.c \
	$(BUILTINDIR)/atomic_signal_fence.c \
	$(BUILTINDIR)/atomic_thread_fence.c \


BUILTIN_FLOAT_BF16 := \
	$(BUILTINDIR)/trunctfdf2.c \
	$(BUILTINDIR)/truncdfbf2.c \
	$(BUILTINDIR)/truncsfbf2.c \


BUILDIN_arm := \
	$(BUILTINDIR)/arm/ltsf2vfp.S \
	$(BUILTINDIR)/arm/sync_fetch_and_and_4.S \
	$(BUILTINDIR)/arm/restore_vfp_d8_d15_regs.S \
	$(BUILTINDIR)/arm/floatunssisfvfp.S \
	$(BUILTINDIR)/arm/sync_fetch_and_nand_4.S \
	$(BUILTINDIR)/arm/subdf3vfp.S \
	$(BUILTINDIR)/arm/aeabi_idivmod.S \
	$(BUILTINDIR)/arm/udivsi3.S \
	$(BUILTINDIR)/arm/mulsf3vfp.S \
	$(BUILTINDIR)/arm/gtsf2vfp.S \
	$(BUILTINDIR)/arm/comparesf2.S \
	$(BUILTINDIR)/arm/bswapsi2.S \
	$(BUILTINDIR)/arm/bswapdi2.S \
	$(BUILTINDIR)/arm/sync_fetch_and_or_8.S \
	$(BUILTINDIR)/arm/truncdfsf2vfp.S \
	$(BUILTINDIR)/arm/switchu8.S \
	$(BUILTINDIR)/arm/aeabi_cdcmpeq_check_nan.c \
	$(BUILTINDIR)/arm/sync_fetch_and_xor_4.S \
	$(BUILTINDIR)/arm/divdf3vfp.S \
	$(BUILTINDIR)/arm/softfloat-alias.list \
	$(BUILTINDIR)/arm/adddf3vfp.S \
	$(BUILTINDIR)/arm/aeabi_cfcmp.S \
	$(BUILTINDIR)/arm/sync_fetch_and_min_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_add_4.S \
	$(BUILTINDIR)/arm/switch16.S \
	$(BUILTINDIR)/arm/chkstk.S \
	$(BUILTINDIR)/arm/floatsidfvfp.S \
	$(BUILTINDIR)/arm/unordsf2vfp.S \
	$(BUILTINDIR)/arm/aeabi_memmove.S \
	$(BUILTINDIR)/arm/sync_fetch_and_max_8.S \
	$(BUILTINDIR)/arm/aeabi_uidivmod.S \
	$(BUILTINDIR)/arm/eqsf2vfp.S \
	$(BUILTINDIR)/arm/aeabi_div0.c \
	$(BUILTINDIR)/arm/sync_fetch_and_sub_4.S \
	$(BUILTINDIR)/arm/save_vfp_d8_d15_regs.S \
	$(BUILTINDIR)/arm/switch8.S \
	$(BUILTINDIR)/arm/ledf2vfp.S \
	$(BUILTINDIR)/arm/negsf2vfp.S \
	$(BUILTINDIR)/arm/aeabi_dcmp.S \
	$(BUILTINDIR)/arm/sync_fetch_and_umax_4.S \
	$(BUILTINDIR)/arm/sync_synchronize.S \
	$(BUILTINDIR)/arm/modsi3.S \
	$(BUILTINDIR)/arm/sync_fetch_and_umin_8.S \
	$(BUILTINDIR)/arm/nesf2vfp.S \
	$(BUILTINDIR)/arm/gedf2vfp.S \
	$(BUILTINDIR)/arm/aeabi_memset.S \
	$(BUILTINDIR)/arm/fixunssfsivfp.S \
	$(BUILTINDIR)/arm/fp_mode.c \
	$(BUILTINDIR)/arm/switch32.S \
	$(BUILTINDIR)/arm/sync_fetch_and_and_8.S \
	$(BUILTINDIR)/arm/divmodsi4.S \
	$(BUILTINDIR)/arm/divsf3vfp.S \
	$(BUILTINDIR)/arm/sync_fetch_and_nand_8.S \
	$(BUILTINDIR)/arm/extendsfdf2vfp.S \
	$(BUILTINDIR)/arm/addsf3.S \
	$(BUILTINDIR)/arm/addsf3vfp.S \
	$(BUILTINDIR)/arm/udivmodsi4.S \
	$(BUILTINDIR)/arm/aeabi_fcmp.S \
	$(BUILTINDIR)/arm/aeabi_uldivmod.S \
	$(BUILTINDIR)/arm/umodsi3.S \
	$(BUILTINDIR)/arm/ltdf2vfp.S \
	$(BUILTINDIR)/arm/subsf3vfp.S \
	$(BUILTINDIR)/arm/floatsisfvfp.S \
	$(BUILTINDIR)/arm/gtdf2vfp.S \
	$(BUILTINDIR)/arm/muldf3vfp.S \
	$(BUILTINDIR)/arm/aeabi_cfcmpeq_check_nan.c \
	$(BUILTINDIR)/arm/sync_fetch_and_or_4.S \
	$(BUILTINDIR)/arm/clzsi2.S \
	$(BUILTINDIR)/arm/clzdi2.S \
	$(BUILTINDIR)/arm/aeabi_memcpy.S \
	$(BUILTINDIR)/arm/sync_fetch_and_xor_8.S \
	$(BUILTINDIR)/arm/fixdfsivfp.S \
	$(BUILTINDIR)/arm/sync_fetch_and_max_4.S \
	$(BUILTINDIR)/arm/divsi3.S \
	$(BUILTINDIR)/arm/sync-ops.h \
	$(BUILTINDIR)/arm/negdf2vfp.S \
	$(BUILTINDIR)/arm/lesf2vfp.S \
	$(BUILTINDIR)/arm/sync_fetch_and_add_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_min_8.S \
	$(BUILTINDIR)/arm/gesf2vfp.S \
	$(BUILTINDIR)/arm/nedf2vfp.S \
	$(BUILTINDIR)/arm/aeabi_memcmp.S \
	$(BUILTINDIR)/arm/fixsfsivfp.S \
	$(BUILTINDIR)/arm/fixunsdfsivfp.S \
	$(BUILTINDIR)/arm/aeabi_drsub.c \
	$(BUILTINDIR)/arm/unorddf2vfp.S \
	$(BUILTINDIR)/arm/sync_fetch_and_umin_4.S \
	$(BUILTINDIR)/arm/aeabi_cdcmp.S \
	$(BUILTINDIR)/arm/floatunssidfvfp.S \
	$(BUILTINDIR)/arm/sync_fetch_and_sub_8.S \
	$(BUILTINDIR)/arm/aeabi_ldivmod.S \
	$(BUILTINDIR)/arm/sync_fetch_and_umax_8.S \
	$(BUILTINDIR)/arm/aeabi_frsub.c \
	$(BUILTINDIR)/arm/eqdf2vfp.S \


BUILDIN_arm64 := \
	$(BUILTINDIR)/aarch64/lse.S \
	$(BUILTINDIR)/aarch64/chkstk.S \
	$(BUILTINDIR)/aarch64/fp_mode.c \


BUILTIN_ppc := \
	$(BUILTINDIR)/ppc/floatunditf.c \
	$(BUILTINDIR)/ppc/gcc_qmul.c \
	$(BUILTINDIR)/ppc/saveFP.S \
	$(BUILTINDIR)/ppc/fixunstfdi.c \
	$(BUILTINDIR)/ppc/fixtfdi.c \
	$(BUILTINDIR)/ppc/divtc3.c \
	$(BUILTINDIR)/ppc/restFP.S \
	$(BUILTINDIR)/ppc/multc3.c \
	$(BUILTINDIR)/ppc/gcc_qdiv.c \
	$(BUILTINDIR)/ppc/floattitf.c \
	$(BUILTINDIR)/ppc/fixunstfti.c \
	$(BUILTINDIR)/ppc/fixtfti.c \
	$(BUILTINDIR)/ppc/gcc_qsub.c \
	$(BUILTINDIR)/ppc/gcc_qadd.c \
	$(BUILTINDIR)/ppc/atomic.exp \
	$(BUILTINDIR)/ppc/DD.h \
	$(BUILTINDIR)/ppc/floatditf.c \


# only rv32
BUILTIN_rv32i := \
	$(BUILTINDIR)/muldi3.c \
	$(BUILTINDIR)/riscv/mulsi3.S \

BUILTIN_rv32ic := $(BUILTIN_rv32i)

# only rv64
BUILTIN_rv64i := \
	$(BUILTINDIR)/riscv/muldi3.S \

BUILTIN_rv64ic := $(BUILTIN_rv64i)

# all riscv
BUILTIN_riscv := \
	$(BUILTINDIR)/riscv/restore.S \
	$(BUILTINDIR)/riscv/save.S \


BUILTIN_x86 := \
	$(BUILTINDIR)/i386/floatundidf.S \
	$(BUILTINDIR)/i386/udivdi3.S \
	$(BUILTINDIR)/i386/floatundixf.S \
	$(BUILTINDIR)/i386/ashldi3.S \
	$(BUILTINDIR)/i386/chkstk.S \
	$(BUILTINDIR)/i386/ashrdi3.S \
	$(BUILTINDIR)/i386/floatundisf.S \
	$(BUILTINDIR)/i386/moddi3.S \
	$(BUILTINDIR)/i386/fp_mode.c \
	$(BUILTINDIR)/i386/lshrdi3.S \
	$(BUILTINDIR)/i386/umoddi3.S \
	$(BUILTINDIR)/i386/muldi3.S \
	$(BUILTINDIR)/i386/floatdisf.S \
	$(BUILTINDIR)/i386/chkstk2.S \
	$(BUILTINDIR)/i386/divdi3.S \
	$(BUILTINDIR)/i386/floatdixf.S \
	$(BUILTINDIR)/i386/floatdidf.S \


BUILTIN_x86_64 := \
	$(BUILTINDIR)/x86_64/floatundidf.S \
	$(BUILTINDIR)/x86_64/floatundixf.S \
	$(BUILTINDIR)/x86_64/floatdisf.c \
	$(BUILTINDIR)/x86_64/chkstk.S \
	$(BUILTINDIR)/x86_64/floatdidf.c \
	$(BUILTINDIR)/x86_64/floatdixf.c \
	$(BUILTINDIR)/x86_64/floatundisf.S \
	$(BUILTINDIR)/x86_64/chkstk2.S \


BUILTIN_INCLUDES := \
	$(BUILTINDIR)/assembly.h \
	$(BUILTINDIR)/fp_extend.h \
	$(BUILTINDIR)/fp_lib.h \
	$(BUILTINDIR)/fp_mode.h \
	$(BUILTINDIR)/fp_trunc.h \
	$(BUILTINDIR)/int_endianness.h \
	$(BUILTINDIR)/int_lib.h \
	$(BUILTINDIR)/int_math.h \
	$(BUILTINDIR)/int_types.h \
	$(BUILTINDIR)/int_util.h \
	$(BUILTINDIR)/unwind-ehabi-helpers.h \
	$(BUILTINDIR)/int_mulo_impl.inc \
	$(BUILTINDIR)/fp_fixuint_impl.inc \
	$(BUILTINDIR)/fp_mul_impl.inc \
	$(BUILTINDIR)/int_mulv_impl.inc \
	$(BUILTINDIR)/fp_fixint_impl.inc \
	$(BUILTINDIR)/fp_extend_impl.inc \
	$(BUILTINDIR)/int_div_impl.inc \
	$(BUILTINDIR)/fp_div_impl.inc \
	$(BUILTINDIR)/fp_add_impl.inc \
	$(BUILTINDIR)/fp_trunc_impl.inc \
	$(BUILTINDIR)/riscv/int_mul_impl.inc \
	$(BUILTINDIR)/fp_compare_impl.inc \

# REMOVED :=\
# 	$(BUILTINDIR)/apple_versioning.c \
# 	$(BUILTINDIR)/eprintf.c \
# 	$(BUILTINDIR)/clear_cache.c \
# 	$(BUILTINDIR)/emutls.c \
# 	$(BUILTINDIR)/enable_execute_stack.c \
#	$(BUILTINDIR)/ve/grow_stack_align.S \
#	$(BUILTINDIR)/ve/grow_stack.S \

