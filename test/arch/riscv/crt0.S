
    .global main

.text
.global _start
_start:
    .cfi_startproc
    .cfi_undefined ra
    .cfi_undefined sp

    la  gp, __global_pointer$   // set global pointer
    la  sp, __main_stack_base   // initialize the stack
    mv  fp, zero                // zero frame pointer (end of frame linked list)

    li  a0, 0                   // argc = 0
    li  a1, 0                   // argv = NULL
    call main

    mv  a1, a0                  // save main return value
    li  a0, 0x666               // monitor exit
    ecall

    .cfi_endproc

.global platform_abort
platform_abort:
    .cfi_startproc
    li  a1, 1                   // exit error
    li  a0, 0x666               // monitor exit
    ecall
    .cfi_endproc

.data
.align 16
__main_stack:
    .space 4096
__main_stack_base:

.end
