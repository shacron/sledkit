#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include <driver/base.h>
#include <driver/reg.h>

#include <device/sled/mpu.h>

// todo: include platform header
#define PLAT_MEM_BASE 0x10000
#define PLAT_MEM_SIZE (5 * 1024 * 1024)

#define BUFLEN  4096

uint32_t buffer[BUFLEN];

#define LO(x) ((x) & 0xffffffff)
#define HI(x) ((uint64_t)(x) >> 32)

static void mpu_config(uint32_t flags) {
    reg32(PLAT_MPU_BASE, MPU_REG_CONFIG) = flags;
}

void mpu_disable() { mpu_config(0); }
void mpu_enable() { mpu_config(MPU_CONFIG_ENABLE); }
void mpu_apply_enable() { mpu_config(MPU_CONFIG_APPLY | MPU_CONFIG_ENABLE); }

static void mpu_add_mapping(int index, uint64_t va, uint64_t pa, uint32_t size) {
    reg32(PLAT_MPU_BASE, MPU_REG_MAP_VA_BASE_LO(index)) = LO(va);
    reg32(PLAT_MPU_BASE, MPU_REG_MAP_VA_BASE_HI(index)) = HI(va);
    reg32(PLAT_MPU_BASE, MPU_REG_MAP_PA_BASE_LO(index)) = LO(pa);
    reg32(PLAT_MPU_BASE, MPU_REG_MAP_PA_BASE_HI(index)) = HI(pa);
    reg32(PLAT_MPU_BASE, MPU_REG_MAP_LEN(index)) = size;
}

int main(void) {
    printf("mpu test\n");

    uint32_t type = reg32(PLAT_MPU_BASE, MPU_REG_DEV_TYPE);
    uint32_t ver = reg32(PLAT_MPU_BASE, MPU_REG_DEV_VERSION);
    uint32_t config = reg32(PLAT_MPU_BASE, MPU_REG_CONFIG);
    uint32_t status = reg32(PLAT_MPU_BASE, MPU_REG_STATUS);
    uint32_t map_count = reg32(PLAT_MPU_BASE, MPU_REG_MAP_ENTS);


    printf("type:   %#x\n", type);
    printf("ver:    %#x\n", ver);
    printf("config: %#x\n", config);
    printf("status: %#x\n", status);
    printf("map_count: %#x\n", map_count);

    printf("adding identity mapping at %#x, len %u\n", PLAT_MEM_BASE, PLAT_MEM_SIZE);

    mpu_add_mapping(0, PLAT_MEM_BASE, PLAT_MEM_BASE, PLAT_MEM_SIZE);
    mpu_add_mapping(1, PLAT_DEV_BASE, PLAT_DEV_BASE, PLAT_DEV_LENGTH);

    mpu_apply_enable();

    printf("did it work?\n");

    status = reg32(PLAT_MPU_BASE, MPU_REG_STATUS);
    assert(status & MPU_STATUS_ENABLED);

    uintptr_t buf_addr = (uintptr_t)buffer;
    uintptr_t buf_remap = 0x87650000;

    printf("buffer is located at %p, remapping it at %#x\n", buffer, buf_remap);

    mpu_add_mapping(2, buf_remap, buf_addr, BUFLEN * sizeof(uint32_t));

    mpu_apply_enable();

    for (int i = 0; i < BUFLEN; i++) buffer[i] = i;

    uint32_t *b = (uint32_t *)buf_remap;

    for (int i = 0; i < 10; i++) {
        printf("remap[%u] = %u\n", i, b[i]);
    }

    mpu_disable();

    printf("mpu disabled\n");

    return 0;
}
