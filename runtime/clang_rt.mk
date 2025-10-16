BUILTINDIR := $(SOURCEDIR)/builtins

# This file is derived from LLVM's compiler-rt/CMakeLists.txt
# It attempts to maintain the same order for merge purposes

BUILTIN_GENERIC_SOURCES := \
	absvdi2.c \
	absvsi2.c \
	absvti2.c \
	adddf3.c \
	addsf3.c \
	addvdi3.c \
	addvsi3.c \
	addvti3.c \
	apple_versioning.c \
	ashldi3.c \
	ashlti3.c \
	ashrdi3.c \
	ashrti3.c \
	bswapdi2.c \
	bswapsi2.c \
	clzdi2.c \
	clzsi2.c \
	clzti2.c \
	cmpdi2.c \
	cmpti2.c \
	comparedf2.c \
	comparesf2.c \
	ctzdi2.c \
	ctzsi2.c \
	ctzti2.c \
	divdc3.c \
	divdf3.c \
	divdi3.c \
	divmoddi4.c \
	divmodsi4.c \
	divmodti4.c \
	divsc3.c \
	divsf3.c \
	divsi3.c \
	divti3.c \
	extendsfdf2.c \
	extendhfsf2.c \
	extendhfdf2.c \
	ffsdi2.c \
	ffssi2.c \
	ffsti2.c \
	fixdfdi.c \
	fixdfsi.c \
	fixdfti.c \
	fixsfdi.c \
	fixsfsi.c \
	fixsfti.c \
	fixunsdfdi.c \
	fixunsdfsi.c \
	fixunsdfti.c \
	fixunssfdi.c \
	fixunssfsi.c \
	fixunssfti.c \
	floatdidf.c \
	floatdisf.c \
	floatsidf.c \
	floatsisf.c \
	floattidf.c \
	floattisf.c \
	floatundidf.c \
	floatundisf.c \
	floatunsidf.c \
	floatunsisf.c \
	floatuntidf.c \
	floatuntisf.c \
	fp_mode.c \
	int_util.c \
	lshrdi3.c \
	lshrti3.c \
	moddi3.c \
	modsi3.c \
	modti3.c \
	muldc3.c \
	muldf3.c \
	muldi3.c \
	mulodi4.c \
	mulosi4.c \
	muloti4.c \
	mulsc3.c \
	mulsf3.c \
	multi3.c \
	mulvdi3.c \
	mulvsi3.c \
	mulvti3.c \
	negdf2.c \
	negdi2.c \
	negsf2.c \
	negti2.c \
	negvdi2.c \
	negvsi2.c \
	negvti2.c \
	os_version_check.c \
	paritydi2.c \
	paritysi2.c \
	parityti2.c \
	popcountdi2.c \
	popcountsi2.c \
	popcountti2.c \
	powidf2.c \
	powisf2.c \
	subdf3.c \
	subsf3.c \
	subvdi3.c \
	subvsi3.c \
	subvti3.c \
	trampoline_setup.c \
	truncdfhf2.c \
	truncdfsf2.c \
	truncsfhf2.c \
	ucmpdi2.c \
	ucmpti2.c \
	udivdi3.c \
	udivmoddi4.c \
	udivmodsi4.c \
	udivmodti4.c \
	udivsi3.c \
	udivti3.c \
	umoddi3.c \
	umodsi3.c \
	umodti3.c \

# We only build BF16 files when "__bf16" is available.
BUILTIN_BF16_SOURCES := \
	extendbfsf2.c \
	truncdfbf2.c \
	truncxfbf2.c \
	truncsfbf2.c \
	trunctfbf2.c \

BUILTIN_GENERIC_TF_SOURCES := \
	addtf3.c \
	comparetf2.c \
	divtc3.c \
	divtf3.c \
	extenddftf2.c \
	extendhftf2.c \
	extendsftf2.c \
	fixtfdi.c \
	fixtfsi.c \
	fixtfti.c \
	fixunstfdi.c \
	fixunstfsi.c \
	fixunstfti.c \
	floatditf.c \
	floatsitf.c \
	floattitf.c \
	floatunditf.c \
	floatunsitf.c \
	floatuntitf.c \
	multc3.c \
	multf3.c \
	powitf2.c \
	subtf3.c \
	trunctfdf2.c \
	trunctfhf2.c \
	trunctfsf2.c \


# BUILTIN_GENERIC_SOURCES += \
# 	atomic.c \

# if(APPLE)
# BUILTIN_GENERIC_SOURCES += \
# 	atomic_flag_clear.c \
# 	atomic_flag_clear_explicit.c \
# 	atomic_flag_test_and_set.c \
# 	atomic_flag_test_and_set_explicit.c \
# 	atomic_signal_fence.c \
# 	atomic_thread_fence.c \
# endif()

# BUILTIN_GENERIC_SOURCES += \
# 	clear_cache.c

# builtin support for Targets that have Arm state or have Thumb2
BUILTIN_arm_or_thumb2_base_SOURCES := \
	arm/fp_mode.c \
	arm/bswapdi2.S \
	arm/bswapsi2.S \
	arm/clzdi2.S \
	arm/clzsi2.S \
	arm/comparesf2.S \
	arm/divmodsi4.S \
	arm/divsi3.S \
	arm/modsi3.S \
	arm/udivmodsi4.S \
	arm/udivsi3.S \
	arm/umodsi3.S \
	${BUILTIN_GENERIC_SOURCES}

BUILTIN_arm_sync_SOURCES := \
	arm/sync_fetch_and_add_4.S \
	arm/sync_fetch_and_add_8.S \
	arm/sync_fetch_and_and_4.S \
	arm/sync_fetch_and_and_8.S \
	arm/sync_fetch_and_max_4.S \
	arm/sync_fetch_and_max_8.S \
	arm/sync_fetch_and_min_4.S \
	arm/sync_fetch_and_min_8.S \
	arm/sync_fetch_and_nand_4.S \
	arm/sync_fetch_and_nand_8.S \
	arm/sync_fetch_and_or_4.S \
	arm/sync_fetch_and_or_8.S \
	arm/sync_fetch_and_sub_4.S \
	arm/sync_fetch_and_sub_8.S \
	arm/sync_fetch_and_umax_4.S \
	arm/sync_fetch_and_umax_8.S \
	arm/sync_fetch_and_umin_4.S \
	arm/sync_fetch_and_umin_8.S \
	arm/sync_fetch_and_xor_4.S \
	arm/sync_fetch_and_xor_8.S \

# builtin support for Thumb-only targets with very limited Thumb2 technology,
# such as v6-m and v8-m.baseline
BUILTIN_thumb1_base_SOURCES := \
	arm/divsi3.S \
	arm/udivsi3.S \
	arm/comparesf2.S \
	arm/addsf3.S \
	${BUILTIN_GENERIC_SOURCES} \

BUILTIN_arm_EABI_SOURCES := \
	arm/aeabi_cdcmp.S \
	arm/aeabi_cdcmpeq_check_nan.c \
	arm/aeabi_cfcmp.S \
	arm/aeabi_cfcmpeq_check_nan.c \
	arm/aeabi_dcmp.S \
	arm/aeabi_div0.c \
	arm/aeabi_drsub.c \
	arm/aeabi_fcmp.S \
	arm/aeabi_frsub.c \
	arm/aeabi_idivmod.S \
	arm/aeabi_ldivmod.S \
	arm/aeabi_uidivmod.S \
	arm/aeabi_uldivmod.S \

BUILDIN_arm_EABI_CLIB_SOURCES := \
  arm/aeabi_memcmp.S \
  arm/aeabi_memcpy.S \
  arm/aeabi_memmove.S \
  arm/aeabi_memset.S \

# todo: make this optional
arm_EABI_SOURCES += $(BUILDIN_arm_EABI_CLIB_SOURCES)

BUILTIN_arm_Thumb1_JT_SOURCES := \
	arm/switch16.S \
	arm/switch32.S \
	arm/switch8.S \
	arm/switchu8.S \

BUILTIN_arm_Thumb1_SjLj_EH_SOURCES := \
	arm/restore_vfp_d8_d15_regs.S \
	arm/save_vfp_d8_d15_regs.S \

BUILTIN_arm_Thumb1_VFPv2_DP_SOURCES := \
	arm/adddf3vfp.S \
	arm/divdf3vfp.S \
	arm/eqdf2vfp.S \
	arm/extendsfdf2vfp.S \
	arm/fixdfsivfp.S \
	arm/fixunsdfsivfp.S \
	arm/floatsidfvfp.S \
	arm/floatunssidfvfp.S \
	arm/gedf2vfp.S \
	arm/gtdf2vfp.S \
	arm/ledf2vfp.S \
	arm/ltdf2vfp.S \
	arm/muldf3vfp.S \
	arm/nedf2vfp.S \
	arm/negdf2vfp.S \
	arm/subdf3vfp.S \
	arm/truncdfsf2vfp.S \
	arm/unorddf2vfp.S \

BUILTIN_arm_Thumb1_VFPv2_SP_SOURCES := \
	arm/addsf3vfp.S \
	arm/divsf3vfp.S \
	arm/eqsf2vfp.S \
	arm/fixsfsivfp.S \
	arm/fixunssfsivfp.S \
	arm/floatsisfvfp.S \
	arm/floatunssisfvfp.S \
	arm/gesf2vfp.S \
	arm/gtsf2vfp.S \
	arm/lesf2vfp.S \
	arm/ltsf2vfp.S \
	arm/mulsf3vfp.S \
	arm/negsf2vfp.S \
	arm/nesf2vfp.S \
	arm/subsf3vfp.S \
	arm/unordsf2vfp.S \

BUILTIN_arm_Thumb1_icache_SOURCES := \
	arm/sync_synchronize.S \

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
	cpu_model/aarch64.c \
	aarch64/emupac.cpp \
	aarch64/fp_mode.c \

# TODO

# set(COMPILER_RT_AARCH64_FMV_USES_GLOBAL_CONSTRUCTOR NOT(FUCHSIA OR APPLE))

# if (COMPILER_RT_HAS_AARCH64_SME)
#   if (APPLE)
#     list(APPEND aarch64_SOURCES aarch64/arm_apple_sme_abi.s)
#     set_source_files_properties(aarch64/arm_apple_sme_abi.s PROPERTIES COMPILE_FLAGS -march=armv8a+sme)
#     message(STATUS "AArch64 Apple SME ABI routines enabled")
#   elseif (NOT COMPILER_RT_DISABLE_AARCH64_FMV AND COMPILER_RT_HAS_FNO_BUILTIN_FLAG AND COMPILER_RT_AARCH64_FMV_USES_GLOBAL_CONSTRUCTOR)
#     list(APPEND aarch64_SOURCES aarch64/sme-abi.S aarch64/sme-abi-assert.c)
#     if(COMPILER_RT_HAS_ARM_UNALIGNED AND COMPILER_RT_HAS_ARM_FP)
#       list(APPEND aarch64_SOURCES aarch64/sme-libc-opt-memset-memchr.S aarch64/sme-libc-opt-memcpy-memmove.S)
#     elseif(COMPILER_RT_HAS_ARM_UNALIGNED)
#       list(APPEND aarch64_SOURCES aarch64/sme-libc-memset-memchr.c aarch64/sme-libc-opt-memcpy-memmove.S)
#       message(WARNING "AArch64 SME ABI assembly-optimized memset/memchr disabled: target does not have hardware floating-point support.")
#     else()
#       list(APPEND aarch64_SOURCES aarch64/sme-libc-memset-memchr.c aarch64/sme-libc-memcpy-memmove.c)
#       message(WARNING "AArch64 SME ABI assembly-optimized routines disabled: target does not support unaligned accesses.")
#     endif()
#     message(STATUS "AArch64 SME ABI routines enabled")
#     set_source_files_properties(aarch64/sme-libc-memset-memchr.c aarch64/sme-libc-memcpy-memmove.c PROPERTIES COMPILE_FLAGS "-fno-builtin")
#   else()
#     if(COMPILER_RT_DISABLE_AARCH64_FMV)
#       message(WARNING "AArch64 SME ABI routines require function multiversioning support.")
#     endif()
#     if(NOT COMPILER_RT_HAS_FNO_BUILTIN_FLAG)
#       message(WARNING "AArch64 SME ABI routines require '-fno-builtin'")
#     endif()
#     if(NOT (COMPILER_RT_HAS_AUXV OR COMPILER_RT_BAREMETAL_BUILD))
#       message(WARNING "AArch64 SME ABI routines requires sys/auxv.h or COMPILER_RT_BAREMETAL_BUILD flag")
#     endif()
#     message(STATUS "AArch64 SME ABI routines disabled")
#   endif()
# endif()

# # Generate outline atomics helpers from lse.S base
# set(OA_HELPERS_DIR "${CMAKE_CURRENT_BINARY_DIR}/outline_atomic_helpers.dir")
# file(MAKE_DIRECTORY "${OA_HELPERS_DIR}")

# if(CMAKE_HOST_UNIX)
#   set(COMPILER_RT_LINK_OR_COPY create_symlink)
# else()
#   set(COMPILER_RT_LINK_OR_COPY copy)
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
BUILTIN_arm64ec_SOURCES := ${BUILTIN_aarch64_SOURCES}

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
	ppc/divtc3.c \
	ppc/fixtfdi.c \
	ppc/fixunstfdi.c \
	ppc/floatditf.c \
	ppc/floatunditf.c \
	ppc/gcc_qadd.c \
	ppc/gcc_qdiv.c \
	ppc/gcc_qmul.c \
	ppc/gcc_qsub.c \
	ppc/multc3.c \
	${BUILTIN_GENERIC_SOURCES}

BUILTIN_powerpc64_SOURCES += \
	ppc/floattitf.c \
	ppc/fixtfti.c \
	ppc/fixunstfti.c \

BUILTIN_powerpc64le_SOURCES := ${BUILTIN_powerpc64_SOURCES}

BUILTIN_riscv_SOURCES := \
	cpu_model/riscv.c \
	riscv/fp_mode.c \
	riscv/save.S \
	riscv/restore.S \
	${BUILTIN_GENERIC_SOURCES} \
	${BUILTIN_GENERIC_TF_SOURCES} \

BUILTIN_riscv32_PRESOURCES := \
	riscv/mulsi3.S \
	${BUILTIN_riscv_SOURCES}

BUILTIN_riscv64_PRESOURCES := \
	riscv/muldi3.S \
	${BUILTIN_riscv_SOURCES}

BUILTIN_riscv32_SOURCES := $(addprefix ${BUILTINDIR}/, ${BUILTIN_riscv32_PRESOURCES})
BUILTIN_riscv64_SOURCES := $(addprefix ${BUILTINDIR}/, ${BUILTIN_riscv64_PRESOURCES})

