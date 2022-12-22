#include <stdint.h>

#include <driver/base.h>
#include <driver/reg.h>

#include <device/sled/uart.h>

int platform_getchar(void) {
    // todo: wait for data
    return reg32(UART_BASE, UART_REG_FIFO_READ);
}

void platform_putchar(char c) {
    reg32(UART_BASE, UART_REG_FIFO_WRITE) = c;
}
