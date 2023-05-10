#include <stdatomic.h>
#include <stdint.h>
#include <stdio.h>

void barrier_test(void) {
    printf("testing barriers\n");

    atomic_thread_fence(memory_order_relaxed);
    atomic_thread_fence(memory_order_consume);
    atomic_thread_fence(memory_order_acquire);
    atomic_thread_fence(memory_order_release);
    atomic_thread_fence(memory_order_acq_rel);
    atomic_thread_fence(memory_order_seq_cst);

    atomic_signal_fence(memory_order_relaxed);
    atomic_signal_fence(memory_order_consume);
    atomic_signal_fence(memory_order_acquire);
    atomic_signal_fence(memory_order_release);
    atomic_signal_fence(memory_order_acq_rel);
    atomic_signal_fence(memory_order_seq_cst);
}

typedef struct {
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
#if __LP64__
    atomic_ulong ul;
#endif
} atest_t;

int atomic_test(void) {
#if __riscv_atomic
    printf("testing atomic instructions\n");

    atest_t a = {
#if __LP64__
        .ul = 10000000000000,
#endif
        .uc = 5, .us = 1000, .ui = 1000000, };

    atomic_fetch_add_explicit(&a.uc, 3, memory_order_relaxed);
    unsigned char c = atomic_fetch_add_explicit(&a.uc, 3, memory_order_relaxed);
    printf("char %u\n", c);

    atomic_fetch_add_explicit(&a.us, 3, memory_order_relaxed);
    unsigned short s = atomic_fetch_add_explicit(&a.us, 1, memory_order_relaxed);
    printf("short %u\n", s);

    atomic_fetch_add_explicit(&a.ui, 3, memory_order_relaxed);
    unsigned int i = atomic_fetch_add_explicit(&a.ui, 1, memory_order_relaxed);
    printf("int %u\n", i);

#if __LP64__
    atomic_fetch_add_explicit(&a.ul, 3, memory_order_relaxed);
    unsigned long l = atomic_fetch_add_explicit(&a.ul, 1, memory_order_relaxed);
    printf("long %lu\n", l);
#endif

#else
    printf("atomic instructions unsupported!\n");
#endif
    return 0;
}

int main(void) {
    barrier_test();

    if (atomic_test()) {
        return 1;
    }

    return 0;
}
