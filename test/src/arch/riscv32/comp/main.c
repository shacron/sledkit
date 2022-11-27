#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

#if __riscv_xlen == 32
typedef int32_t sxlen_t;
typedef uint32_t uxlen_t;
#define MASK_XLEN(x) ((x) & 0xffffffff)
#define PRIXLENx PRIx32
#else
typedef int64_t  sxlen_t;
typedef uint64_t uxlen_t;
#define MASK_XLEN(x) ((x) & 0xffffffffffffffff)
#define PRIXLENx PRIx64
#endif

uint32_t total = 0;
uint32_t failed = 0;

#define SEXT_IMM(x) ((x) | (-(((x) >> 11) & 1) << 11))

#define TEST_IMM_OP(inst, destreg, reg, correctval, val, imm, swreg, offset, testreg) \
    dst = 0; \
    src = MASK_XLEN(val); \
    if (destreg == 0) { \
        __asm__ __volatile__(#inst " x0, %0, " #imm :: "r" (src)); \
        printf(#inst " x0,  src=" #val ", imm=" #imm " = %" PRIXLENx "\n", dst); \
    } else if (reg == 0) { \
        __asm__ __volatile__(#inst " %0, x0, " #imm : "=r" (dst)); \
        printf(#inst " dst, x0,  imm=" #imm " = %" PRIXLENx "\n", dst); \
    } else { \
        __asm__ __volatile__(#inst " %0, %1, " #imm : "=r" (dst) : "r" (src)); \
        printf(#inst " dst, src=" #val ", imm=" #imm " = %" PRIXLENx "\n", dst); \
    } \
    if (dst != correctval) { \
        printf("     FAILED: expected %x, got %" PRIXLENx "\n", correctval, dst); \
        failed++; \
    } \
    total++;

void test_imm(void) {
    uxlen_t dst, src;

    #include "rv32i_imm.h"
}

#define TEST_RR_OP(inst, destreg, reg1, reg2, correctval, val1, val2, swreg, offset, testreg) \
    dst = 0; \
    r1 = MASK_XLEN(val1); \
    r2 = MASK_XLEN(val2); \
   if (destreg == 0) { \
        __asm__ __volatile__(#inst " x0, %[r1], %[r2]" :: [r1] "r" (r1), [r2] "r" (r2)); \
        printf(#inst " x0 , r1=" #val1 ", r2=" #val2 " = %" PRIXLENx "\n", dst); \
    } else if (r1 == 0) { \
        __asm__ __volatile__(#inst " %[dst], x0, %[r2]" : [dst] "=r" (dst) : [r2] "r" (r2)); \
        printf(#inst " dst, x0, r2=" #val2 " = %" PRIXLENx "\n", dst); \
    } else if (r2 == 0) { \
        __asm__ __volatile__(#inst " %[dst], %[r1], x0" : [dst] "=r" (dst) : [r1] "r" (r1)); \
        printf(#inst " dst, r1=" #val1 ", x0 = %" PRIXLENx "\n", dst); \
    } else { \
        __asm__ __volatile__(#inst " %[dst], %[r1], %[r2]" : [dst] "=r" (dst) : [r1] "r" (r1), [r2] "r" (r2)); \
        printf(#inst " dst, r1=" #val1 ", r2=" #val2 " = %" PRIXLENx "\n", dst); \
    } \
    if (dst != correctval) { \
        printf("     FAILED: expected %x, got %" PRIXLENx "\n", correctval, dst); \
        failed++; \
    } \

void test_rr(void) {
    uxlen_t dst, r1, r2;

    #include "rv32i_rr.h"
}

int main(void) {
    printf("RISCV conformance tests\n");

    test_imm();
    test_rr();

    printf("total: %u\n", total);
    printf("failed: %u\n", failed);

    if (failed > 0) return 1;
    return 0;
}
