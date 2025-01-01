#include <stdio.h>

void crash() {
#if __LP32__
    int *p = (int *)0xffffabcd;
#else
    int *p = (int *)0xffffffff12345678;
#endif
    printf("generating crash at %p\n", p);

    int x = *p;
    printf("should not reach here: %d\n", x);
}

int main(void) {
    crash();
    return 0;
}
