#pragma once

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dummy libmin for bringup-bench

#define TRUE true
#define FALSE false

#define libmin_atoi atoi
#define libmin_fail(v) exit(v)
#define libmin_printf printf
#define libmin_putc putchar
#define libmin_strcpy strcpy
#define libmin_strcmp strcmp
#define libmin_strlen strlen
#define libmin_strncat strncat
#define libmin_strncpy strncpy
#define libmin_success() do {} while(0)


