#include <stdint.h>

#include <driver/base.h>
#include <driver/reg.h>

#include <sled/device/uart.h>

void platform_putchar(char c) {
    reg32(UART_BASE, UART_REG_FIFO_WRITE) = c;
}
