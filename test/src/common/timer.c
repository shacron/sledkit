#include <assert.h>
#include <stdio.h>

#include <driver/base.h>
#include <driver/reg.h>

#include <device/sled/intc.h>
#include <device/sled/timer.h>

#define TIMER_INT_BIT   0   // platform dependent. Todo: export platform files
#define TIMER_INT       (1u <<  TIMER_INT_BIT)

static void wait_for_looped() {
    for ( ; ; ) {
        uint32_t val = reg32(PLAT_TIMER_BASE, TIMER_REG_UNIT_CONFIG(0));
        if (val & TIMER_UNIT_CONFIG_LOOPED) break;
    }
}

static void clear_intc(void) {
    reg32(PLAT_INTC_BASE, INTC_REG_ASSERTED) = TIMER_INT;
}

static void clear_timer_asserted(int num) {
    reg32(PLAT_TIMER_BASE, TIMER_IRQ_STATUS) = (1u << num);
}

static void print_intc_asserted(void) {
    uint32_t ic_asserted = reg32(PLAT_INTC_BASE, INTC_REG_ASSERTED);
    printf("INTC asserted:  %8x\n", ic_asserted);
}

static void print_timer_asserted(void) {
    uint32_t timer_asserted = reg32(PLAT_TIMER_BASE, TIMER_IRQ_STATUS);
    printf("TIMER asserted: %8x\n", timer_asserted);
}


int main(void) {
    printf("timer test\n");

    uint32_t val = reg32(PLAT_TIMER_BASE, TIMER_REG_DEV_TYPE);
    printf("type    = %c%c%c%c\n", (val >> 24) & 0xff, (val >> 16) & 0xff, (val >> 8) & 0xff, val & 0xff);
    val = reg32(PLAT_TIMER_BASE, TIMER_REG_DEV_VERSION);
    printf("version = %u\n", val);

    val = reg32(PLAT_TIMER_BASE, TIMER_IRQ_MASK);
    printf("irq mask   = %x\n", val);
    val = reg32(PLAT_TIMER_BASE, TIMER_IRQ_STATUS);
    printf("irq status = %x\n", val);


    val = reg32(PLAT_TIMER_BASE, TIMER_REG_RT_SCALER_US);
    printf("scalar  = %u\n", val);
    val = reg32(PLAT_TIMER_BASE, TIMER_REG_NUM_UNITS);
    printf("units   = %u\n", val);

    printf("setting 1 second timer\n");

    const uint64_t count_us = 3 * 1000 * 1000;

    reg32(PLAT_TIMER_BASE, TIMER_REG_UNIT_RESET_VAL_LO(0)) = (uint32_t)count_us;
    reg32(PLAT_TIMER_BASE, TIMER_REG_UNIT_RESET_VAL_HI(0)) = (uint32_t)(count_us >> 32);

    reg32(PLAT_TIMER_BASE, TIMER_REG_UNIT_CONFIG(0)) = TIMER_UNIT_CONFIG_RUN;

    wait_for_looped();

    printf("done, restarting timer\n");

    reg32(PLAT_TIMER_BASE, TIMER_REG_UNIT_CONFIG(0)) = TIMER_UNIT_CONFIG_RUN;

    wait_for_looped();

    printf("looped, enabling interrupt\n");

    clear_timer_asserted(0);                    // clear pending interrupt
    reg32(PLAT_TIMER_BASE, TIMER_IRQ_MASK) = 0; // clear interrupt mask

    printf("running continuous\n");
    reg32(PLAT_TIMER_BASE, TIMER_REG_UNIT_CONFIG(0)) = TIMER_UNIT_CONFIG_RUN | TIMER_UNIT_CONFIG_CONTINUOUS;

    wait_for_looped();
    print_intc_asserted();

    clear_timer_asserted(0);
    clear_intc();
    print_intc_asserted();

    printf("waiting for next interrupt\n");
    for ( ; ; ) {
        val = reg32(PLAT_TIMER_BASE, TIMER_IRQ_STATUS);
        if (val != 0) break;
    }
    reg32(PLAT_TIMER_BASE, TIMER_REG_UNIT_CONFIG(0)) = 0;   // stop timer

    print_timer_asserted();
    print_intc_asserted();
    return 0;
}
