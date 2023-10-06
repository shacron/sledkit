#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 512

int test_memset_one(uint8_t *p, uint32_t offset, uint32_t len) {
    memset(p, 0, BUFLEN);

    printf("memset offset=%u, len=%u\n", offset, len);

    void *rp = memset(p + offset, 0x5a, len);
    if (rp != p + offset) {
        printf("failed to return input pointer\n");
        return -1;
    }

    uint32_t i;
    for (i = 0; i < offset; i++) {
        if (p[i] != 0) {
            printf("unexpected value pre-offset, index=%u\n", i);
            return -1;
        }
    }
    for ( ; i < offset + len; i++) {
        if (p[i] != 0x5a) {
            printf("unexpected set value, index=%u\n", i);
            return -1;
        }
    }
    for ( ; i < BUFLEN; i++) {
        if (p[i] != 0) {
            printf("unexpected value post length, index=%u\n", i);
            return -1;
        }
    }
    return 0;
}

uint8_t buf[BUFLEN];

int test_memset(void) {
    uint8_t *p = buf;
    int err = 0;

    for (uint32_t offset = 0; offset < 22; offset++) {
        for (uint32_t len = 0; len <= 37; len++) {
            err = test_memset_one(p, offset, len);
            if (err) goto out;
        }
    }
out:
    return err;
}

int main(void) {
    if (test_memset()) {
        printf("memset test failed\n");
        return 1;
    }
    printf("memset test ok\n");
    return 0;
}
