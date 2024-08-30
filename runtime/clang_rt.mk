BUILTINDIR := $(SOURCEDIR)/builtins

# This file is derived from LLVM's compiler-rt/CMakeLists.txt
# It attempts to maintain the same order for merge purposes

BUILTIN_GENERIC_SOURCES := \
	$(BUILTINDIR)/absvdi2.c \
	$(BUILTINDIR)/absvsi2.c \
	$(BUILTINDIR)/absvti2.c \
	$(BUILTINDIR)/adddf3.c \
	$(BUILTINDIR)/addsf3.c \
	$(BUILTINDIR)/addvdi3.c \
	$(BUILTINDIR)/addvsi3.c \
	$(BUILTINDIR)/addvti3.c \
	$(BUILTINDIR)/apple_versioning.c \
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
	$(BUILTINDIR)/divti3.c \
	$(BUILTINDIR)/extendsfdf2.c \
	$(BUILTINDIR)/extendhfsf2.c \
	$(BUILTINDIR)/ffsdi2.c \
	$(BUILTINDIR)/ffssi2.c \
	$(BUILTINDIR)/ffsti2.c \
	$(BUILTINDIR)/fixdfdi.c \
	$(BUILTINDIR)/fixdfsi.c \
	$(BUILTINDIR)/fixdfti.c \
	$(BUILTINDIR)/fixsfdi.c \
	$(BUILTINDIR)/fixsfsi.c \
	$(BUILTINDIR)/fixsfti.c \
	$(BUILTINDIR)/fixunsdfdi.c \
	$(BUILTINDIR)/fixunsdfsi.c \
	$(BUILTINDIR)/fixunsdfti.c \
	$(BUILTINDIR)/fixunssfdi.c \
	$(BUILTINDIR)/fixunssfsi.c \
	$(BUILTINDIR)/fixunssfti.c \
	$(BUILTINDIR)/floatdidf.c \
	$(BUILTINDIR)/floatdisf.c \
	$(BUILTINDIR)/floatsidf.c \
	$(BUILTINDIR)/floatsisf.c \
	$(BUILTINDIR)/floattidf.c \
	$(BUILTINDIR)/floattisf.c \
	$(BUILTINDIR)/floatundidf.c \
	$(BUILTINDIR)/floatundisf.c \
	$(BUILTINDIR)/floatunsidf.c \
	$(BUILTINDIR)/floatunsisf.c \
	$(BUILTINDIR)/floatuntidf.c \
	$(BUILTINDIR)/floatuntisf.c \
	$(BUILTINDIR)/fp_mode.c \
	$(BUILTINDIR)/int_util.c \
	$(BUILTINDIR)/lshrdi3.c \
	$(BUILTINDIR)/lshrti3.c \
	$(BUILTINDIR)/moddi3.c \
	$(BUILTINDIR)/modsi3.c \
	$(BUILTINDIR)/modti3.c \
	$(BUILTINDIR)/muldc3.c \
	$(BUILTINDIR)/muldf3.c \
	$(BUILTINDIR)/muldi3.c \
	$(BUILTINDIR)/mulodi4.c \
	$(BUILTINDIR)/mulosi4.c \
	$(BUILTINDIR)/muloti4.c \
	$(BUILTINDIR)/mulsc3.c \
	$(BUILTINDIR)/mulsf3.c \
	$(BUILTINDIR)/multi3.c \
	$(BUILTINDIR)/mulvdi3.c \
	$(BUILTINDIR)/mulvsi3.c \
	$(BUILTINDIR)/mulvti3.c \
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
	$(BUILTINDIR)/subdf3.c \
	$(BUILTINDIR)/subsf3.c \
	$(BUILTINDIR)/subvdi3.c \
	$(BUILTINDIR)/subvsi3.c \
	$(BUILTINDIR)/subvti3.c \
	$(BUILTINDIR)/trampoline_setup.c \
	$(BUILTINDIR)/truncdfhf2.c \
	$(BUILTINDIR)/truncdfsf2.c \
	$(BUILTINDIR)/truncsfhf2.c \
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

# We only build BF16 files when "__bf16" is available.
BUILTIN_BF16_SOURCES := \
	$(BUILTINDIR)/truncdfbf2.c \
	$(BUILTINDIR)/truncsfbf2.c \

BUILTIN_GENERIC_TF_SOURCES := \
	$(BUILTINDIR)/addtf3.c \
	$(BUILTINDIR)/comparetf2.c \
	$(BUILTINDIR)/divtc3.c \
	$(BUILTINDIR)/divtf3.c \
	$(BUILTINDIR)/extenddftf2.c \
	$(BUILTINDIR)/extendhftf2.c \
	$(BUILTINDIR)/extendsftf2.c \
	$(BUILTINDIR)/fixtfdi.c \
	$(BUILTINDIR)/fixtfsi.c \
	$(BUILTINDIR)/fixtfti.c \
	$(BUILTINDIR)/fixunstfdi.c \
	$(BUILTINDIR)/fixunstfsi.c \
	$(BUILTINDIR)/fixunstfti.c \
	$(BUILTINDIR)/floatditf.c \
	$(BUILTINDIR)/floatsitf.c \
	$(BUILTINDIR)/floattitf.c \
	$(BUILTINDIR)/floatunditf.c \
	$(BUILTINDIR)/floatunsitf.c \
	$(BUILTINDIR)/floatuntitf.c \
	$(BUILTINDIR)/multc3.c \
	$(BUILTINDIR)/multf3.c \
	$(BUILTINDIR)/powitf2.c \
	$(BUILTINDIR)/subtf3.c \
	$(BUILTINDIR)/trunctfdf2.c \
	$(BUILTINDIR)/trunctfhf2.c \
	$(BUILTINDIR)/trunctfsf2.c \

# option(COMPILER_RT_EXCLUDE_ATOMIC_BUILTIN
#   "Skip the atomic builtin (these should normally be provided by a shared library)"
#   On)

# if(COMPILER_RT_HAS_ATOMIC_KEYWORD AND NOT COMPILER_RT_EXCLUDE_ATOMIC_BUILTIN)
# BUILTIN_GENERIC_SOURCES += \
# 	$(BUILTINDIR)/atomic.c \

# endif()

# if(APPLE)
# BUILTIN_GENERIC_SOURCES += \
# 	$(BUILTINDIR)/atomic_flag_clear.c \
# 	$(BUILTINDIR)/atomic_flag_clear_explicit.c \
# 	$(BUILTINDIR)/atomic_flag_test_and_set.c \
# 	$(BUILTINDIR)/atomic_flag_test_and_set_explicit.c \
# 	$(BUILTINDIR)/atomic_signal_fence.c \
# 	$(BUILTINDIR)/atomic_thread_fence.c \
# endif()

# if (HAVE_UNWIND_H)
# BUILTIN_GENERIC_SOURCES += \
# 	$(BUILTINDIR)/gcc_personality_v0.c \
# endif ()

# BUILTIN_GENERIC_SOURCES += \
# 	$(BUILTINDIR)/clear_cache.c

# builtin support for Targets that have Arm state or have Thumb2
BUILTIN_arm_or_thumb2_base_SOURCES := \
	$(BUILTINDIR)/arm/fp_mode.c \
	$(BUILTINDIR)/arm/bswapdi2.S \
	$(BUILTINDIR)/arm/bswapsi2.S \
	$(BUILTINDIR)/arm/clzdi2.S \
	$(BUILTINDIR)/arm/clzsi2.S \
	$(BUILTINDIR)/arm/comparesf2.S \
	$(BUILTINDIR)/arm/divmodsi4.S \
	$(BUILTINDIR)/arm/divsi3.S \
	$(BUILTINDIR)/arm/modsi3.S \
	$(BUILTINDIR)/arm/udivmodsi4.S \
	$(BUILTINDIR)/arm/udivsi3.S \
	$(BUILTINDIR)/arm/umodsi3.S \
	${BUILTIN_GENERIC_SOURCES}

BUILTIN_arm_sync_SOURCES := \
	$(BUILTINDIR)/arm/sync_fetch_and_add_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_add_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_and_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_and_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_max_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_max_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_min_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_min_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_nand_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_nand_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_or_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_or_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_sub_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_sub_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_umax_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_umax_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_umin_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_umin_8.S \
	$(BUILTINDIR)/arm/sync_fetch_and_xor_4.S \
	$(BUILTINDIR)/arm/sync_fetch_and_xor_8.S \

# builtin support for Thumb-only targets with very limited Thumb2 technology,
# such as v6-m and v8-m.baseline
BUILTIN_thumb1_base_SOURCES := \
	$(BUILTINDIR)/arm/divsi3.S \
	$(BUILTINDIR)/arm/udivsi3.S \
	$(BUILTINDIR)/arm/comparesf2.S \
	$(BUILTINDIR)/arm/addsf3.S \
	${BUILTIN_GENERIC_SOURCES} \

BUILTIN_arm_EABI_SOURCES := \
	$(BUILTINDIR)/arm/aeabi_cdcmp.S \
	$(BUILTINDIR)/arm/aeabi_cdcmpeq_check_nan.c \
	$(BUILTINDIR)/arm/aeabi_cfcmp.S \
	$(BUILTINDIR)/arm/aeabi_cfcmpeq_check_nan.c \
	$(BUILTINDIR)/arm/aeabi_dcmp.S \
	$(BUILTINDIR)/arm/aeabi_div0.c \
	$(BUILTINDIR)/arm/aeabi_drsub.c \
	$(BUILTINDIR)/arm/aeabi_fcmp.S \
	$(BUILTINDIR)/arm/aeabi_frsub.c \
	$(BUILTINDIR)/arm/aeabi_idivmod.S \
	$(BUILTINDIR)/arm/aeabi_ldivmod.S \
	$(BUILTINDIR)/arm/aeabi_memcmp.S \
	$(BUILTINDIR)/arm/aeabi_memcpy.S \
	$(BUILTINDIR)/arm/aeabi_memmove.S \
	$(BUILTINDIR)/arm/aeabi_memset.S \
	$(BUILTINDIR)/arm/aeabi_uidivmod.S \
	$(BUILTINDIR)/arm/aeabi_uldivmod.S \

BUILTIN_arm_Thumb1_JT_SOURCES := \
	$(BUILTINDIR)/arm/switch16.S \
	$(BUILTINDIR)/arm/switch32.S \
	$(BUILTINDIR)/arm/switch8.S \
	$(BUILTINDIR)/arm/switchu8.S \

BUILTIN_arm_Thumb1_SjLj_EH_SOURCES := \
	$(BUILTINDIR)/arm/restore_vfp_d8_d15_regs.S \
	$(BUILTINDIR)/arm/save_vfp_d8_d15_regs.S \

BUILTIN_arm_Thumb1_VFPv2_DP_SOURCES := \
	$(BUILTINDIR)/arm/adddf3vfp.S \
	$(BUILTINDIR)/arm/divdf3vfp.S \
	$(BUILTINDIR)/arm/eqdf2vfp.S \
	$(BUILTINDIR)/arm/extendsfdf2vfp.S \
	$(BUILTINDIR)/arm/fixdfsivfp.S \
	$(BUILTINDIR)/arm/fixunsdfsivfp.S \
	$(BUILTINDIR)/arm/floatsidfvfp.S \
	$(BUILTINDIR)/arm/floatunssidfvfp.S \
	$(BUILTINDIR)/arm/gedf2vfp.S \
	$(BUILTINDIR)/arm/gtdf2vfp.S \
	$(BUILTINDIR)/arm/ledf2vfp.S \
	$(BUILTINDIR)/arm/ltdf2vfp.S \
	$(BUILTINDIR)/arm/muldf3vfp.S \
	$(BUILTINDIR)/arm/nedf2vfp.S \
	$(BUILTINDIR)/arm/negdf2vfp.S \
	$(BUILTINDIR)/arm/subdf3vfp.S \
	$(BUILTINDIR)/arm/truncdfsf2vfp.S \
	$(BUILTINDIR)/arm/unorddf2vfp.S \

BUILTIN_arm_Thumb1_VFPv2_SP_SOURCES := \
	$(BUILTINDIR)/arm/addsf3vfp.S \
	$(BUILTINDIR)/arm/divsf3vfp.S \
	$(BUILTINDIR)/arm/eqsf2vfp.S \
	$(BUILTINDIR)/arm/fixsfsivfp.S \
	$(BUILTINDIR)/arm/fixunssfsivfp.S \
	$(BUILTINDIR)/arm/floatsisfvfp.S \
	$(BUILTINDIR)/arm/floatunssisfvfp.S \
	$(BUILTINDIR)/arm/gesf2vfp.S \
	$(BUILTINDIR)/arm/gtsf2vfp.S \
	$(BUILTINDIR)/arm/lesf2vfp.S \
	$(BUILTINDIR)/arm/ltsf2vfp.S \
	$(BUILTINDIR)/arm/mulsf3vfp.S \
	$(BUILTINDIR)/arm/negsf2vfp.S \
	$(BUILTINDIR)/arm/nesf2vfp.S \
	$(BUILTINDIR)/arm/subsf3vfp.S \
	$(BUILTINDIR)/arm/unordsf2vfp.S \

BUILTIN_arm_Thumb1_icache_SOURCES := \
	$(BUILTINDIR)/arm/sync_synchronize.S \

# thumb1 calling into Arm to cover support
BUILTIN_arm_Thumb1_SOURCES := \
	${BUILTIN_arm_Thumb1_JT_SOURCES} \
	${BUILTIN_arm_Thumb1_SjLj_EH_SOURCES} \
	${BUILTIN_arm_Thumb1_VFPv2_DP_SOURCES} \
	${BUILTIN_arm_Thumb1_VFPv2_SP_SOURCES} \
	${BUILTIN_arm_Thumb1_icache_SOURCES} \

# base functionality for Arm Targets prior to Arm v7-a and Armv6-m such as v6,
# v5t, v4t
BUILTIN_arm_min_SOURCES := \
	${BUILTIN_arm_or_thumb2_base_SOURCES} \
	${BUILTIN_arm_EABI_SOURCES} \

# TODO the EABI sources should only be added to EABI targets
BUILTIN_arm_SOURCES := \
	${BUILTIN_arm_or_thumb2_base_SOURCES} \
	${BUILTIN_arm_sync_SOURCES} \
	${BUILTIN_arm_EABI_SOURCES} \
	${BUILTIN_arm_Thumb1_SOURCES} \

BUILTIN_thumb1_SOURCES := \
	${BUILTIN_thumb1_base_SOURCES} \
	${BUILTIN_arm_EABI_SOURCES} \

BUILTIN_aarch64_SOURCES := \
	${BUILTIN_GENERIC_TF_SOURCES} \
	${BUILTIN_GENERIC_SOURCES} \
	$(BUILTINDIR)/cpu_model/aarch64.c \
	$(BUILTINDIR)/aarch64/fp_mode.c \

# TODO

# if(COMPILER_RT_HAS_AARCH64_SME AND COMPILER_RT_HAS_FNO_BUILTIN_FLAG AND (COMPILER_RT_HAS_AUXV OR COMPILER_RT_BAREMETAL_BUILD))
#   list(APPEND aarch64_SOURCES aarch64/sme-abi.S aarch64/sme-abi-init.c aarch64/sme-libc-routines.c)
#   message(STATUS "AArch64 SME ABI routines enabled")
#   set_source_files_properties(aarch64/sme-libc-routines.c PROPERTIES COMPILE_FLAGS "-fno-builtin")
# else()
#   message(STATUS "AArch64 SME ABI routines disabled")
# endif()

# foreach(pat cas swp ldadd ldclr ldeor ldset)
#   foreach(size 1 2 4 8 16)
#     foreach(model 1 2 3 4 5)
#       if(pat STREQUAL "cas" OR NOT size STREQUAL "16")
#         set(source_asm "${CMAKE_CURRENT_SOURCE_DIR}/aarch64/lse.S")
#         set(helper_asm "${OA_HELPERS_DIR}/outline_atomic_${pat}${size}_${model}.S")
#         add_custom_command(
#           OUTPUT "${helper_asm}"
#           COMMAND ${CMAKE_COMMAND} -E ${COMPILER_RT_LINK_OR_COPY} "${source_asm}" "${helper_asm}"
#           DEPENDS "${source_asm}"
#         )
#         set_source_files_properties("${helper_asm}"
#           PROPERTIES
#           COMPILE_DEFINITIONS "L_${pat};SIZE=${size};MODEL=${model}"
#           INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}"
#         )
#         list(APPEND aarch64_SOURCES "${helper_asm}")
#       endif()
#     endforeach(model)
#   endforeach(size)
# endforeach(pat)

BUILTIN_armv4t_SOURCES := ${BUILTIN_arm_min_SOURCES}
BUILTIN_armv5te_SOURCES := ${BUILTIN_arm_min_SOURCES}
BUILTIN_armv6_SOURCES := ${BUILTIN_arm_min_SOURCES}
BUILTIN_armhf_SOURCES := ${BUILTIN_arm_SOURCES}
BUILTIN_armv7_SOURCES := ${BUILTIN_arm_SOURCES}
BUILTIN_armv7s_SOURCES := ${BUILTIN_arm_SOURCES}
BUILTIN_armv7k_SOURCES := ${BUILTIN_arm_SOURCES}
BUILTIN_arm64_SOURCES := ${BUILTIN_aarch64_SOURCES}
BUILTIN_arm64e_SOURCES := ${BUILTIN_aarch64_SOURCES}
BUILTIN_arm64_32_SOURCES := ${BUILTIN_aarch64_SOURCES}

# macho_embedded archs
BUILTIN_armv6m_SOURCES := ${BUILTIN_thumb1_SOURCES}
BUILTIN_armv7m_SOURCES := ${BUILTIN_arm_SOURCES}
BUILTIN_armv7em_SOURCES := ${BUILTIN_arm_SOURCES}
BUILTIN_armv8m_base_SOURCES := ${BUILTIN_thumb1_SOURCES}
BUILTIN_armv8m_main_SOURCES := ${BUILTIN_arm_SOURCES}
BUILTIN_armv8_1m_main_SOURCES := ${BUILTIN_arm_SOURCES}

BUILTIN_mips_SOURCES := ${BUILTIN_GENERIC_SOURCES}
BUILTIN_mipsel_SOURCES := ${BUILTIN_mips_SOURCES}
BUILTIN_mips64_SOURCES := ${BUILTIN_GENERIC_TF_SOURCES} ${BUILTIN_mips_SOURCES}
BUILTIN_mips64el_SOURCES := ${BUILTIN_GENERIC_TF_SOURCES} ${BUILTIN_mips_SOURCES}

BUILTIN_powerpc_SOURCES := ${BUILTIN_GENERIC_SOURCES}
BUILTIN_powerpcspe_SOURCES := ${BUILTIN_GENERIC_SOURCES}

BUILTIN_powerpc64_SOURCES := \
	$(BUILTINDIR)/ppc/divtc3.c \
	$(BUILTINDIR)/ppc/fixtfdi.c \
	$(BUILTINDIR)/ppc/fixunstfdi.c \
	$(BUILTINDIR)/ppc/floatditf.c \
	$(BUILTINDIR)/ppc/floatunditf.c \
	$(BUILTINDIR)/ppc/gcc_qadd.c \
	$(BUILTINDIR)/ppc/gcc_qdiv.c \
	$(BUILTINDIR)/ppc/gcc_qmul.c \
	$(BUILTINDIR)/ppc/gcc_qsub.c \
	$(BUILTINDIR)/ppc/multc3.c \
	${BUILTIN_GENERIC_SOURCES}

BUILTIN_powerpc64_SOURCES += \
	$(BUILTINDIR)/ppc/floattitf.c \
	$(BUILTINDIR)/ppc/fixtfti.c \
	$(BUILTINDIR)/ppc/fixunstfti.c \

BUILTIN_powerpc64le_SOURCES := ${BUILTIN_powerpc64_SOURCES}

BUILTIN_riscv_SOURCES := \
	$(BUILTINDIR)/riscv/fp_mode.c \
	$(BUILTINDIR)/riscv/save.S \
	$(BUILTINDIR)/riscv/restore.S \
	${BUILTIN_GENERIC_SOURCES} \
	${BUILTIN_GENERIC_TF_SOURCES} \

BUILTIN_riscv32_SOURCES := \
	$(BUILTINDIR)/riscv/mulsi3.S \
	${BUILTIN_riscv_SOURCES}

BUILTIN_riscv64_SOURCES := \
	$(BUILTINDIR)/riscv/muldi3.S \
	${BUILTIN_riscv_SOURCES}

