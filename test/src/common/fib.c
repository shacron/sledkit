#include <stdint.h>
#include <stdio.h>

void test_fib_loop(uint32_t num) {
    uint32_t a = 0;
    uint32_t b = 1;

    for (uint32_t i = 0; i < num; i++) {
        uint32_t sum = a + b;
        a = b;
        b = sum;
        printf("%u ", b);
    }
    printf("\n");
}

int main(void) {
    for (uint32_t i = 0; i < 15; i++) {
        test_fib_loop(i);
    }
    return 0;
}
