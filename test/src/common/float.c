#include <stdint.h>
#include <stdio.h>

float __attribute__ ((noinline)) add(float a, float b) {
    return a + b;
}

int main(void) {
    float v = add(0.1f, 0.1f);
    printf("result: %x\n", *(uint32_t *)&v);
    return 0;
}
