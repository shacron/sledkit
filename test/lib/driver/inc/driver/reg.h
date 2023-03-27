#pragma once

#include <stdint.h>

#define reg32(base, offset) *(volatile uint32_t*)(uintptr_t)((base)+(offset))
#define reg64(base, offset) *(volatile uint64_t*)(uintptr_t)((base)+(offset))
