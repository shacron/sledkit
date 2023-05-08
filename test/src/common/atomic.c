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
    atomic_ulong ul;
    atomic_ullong ull;
} atest_t;

int atomic_test(void) {
#if __riscv_atomic
    printf("testing atomic instructions\n");

    atest_t a = {};

    unsigned int i;
    i = atomic_fetch_add_explicit(&a.ui, 2, memory_order_relaxed);
    i = atomic_fetch_add_explicit(&a.ui, 1, memory_order_relaxed);
    printf("got %u\n", i);

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
