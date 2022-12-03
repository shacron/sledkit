/*
RISC-V Compliance Test ADD-01
Copyright (c) 2019, Imperas Software Ltd.
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the Imperas Software Ltd. nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Imperas Software Ltd. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
Specification: RV32I Base Integer Instruction Set, Version 2.1
*/

	// TEST_IMM_OP(_inst, _dest, _r1, _correctval, _val, _imm, _swreg, _offset, _testreg)

	TEST_IMM_OP(addi,  0, 31, 0x0000000000000000, -0x1, 0x0, 5, 0, 6)   // Testcase 0
	TEST_IMM_OP(addi,  1, 30, 0xfffffffffffff802, 0x1, -0x7ff, 5, 4, 6)   // Testcase 1
	TEST_IMM_OP(addi,  2, 29, 0xffffffffffffffff, 0x0, -0x1, 5, 8, 6)   // Testcase 2
	TEST_IMM_OP(addi,  3, 28, 0xffffffffffffffff, 0x7ff, -0x800, 5, 12, 6)   // Testcase 3
	TEST_IMM_OP(addi,  4, 27, 0xfffffffffffff800, 0x0, -0x800, 5, 16, 6)   // Testcase 4
	TEST_IMM_OP(addi,  5, 26, 0x0000000000000000, 0x800, -0x800, 1, 0, 2)   // Testcase 5
	TEST_IMM_OP(addi,  6, 25, 0x0000000007653b21, 0x7654321, -0x800, 1, 4, 2)   // Testcase 6
	TEST_IMM_OP(addi,  7, 24, 0x0000000080000000, 0x7fffffff, 0x1, 1, 8, 2)   // Testcase 7
	TEST_IMM_OP(addi,  8, 23, 0xfffffffffffff801, 0x1, -0x800, 1, 12, 2)   // Testcase 8
	TEST_IMM_OP(addi,  9, 22, 0xfffffffffffff7ff, 0xffffffffffffffff, -0x800, 1, 16, 2)   // Testcase 9
	TEST_IMM_OP(addi, 10, 21, 0x0000000000000a34, 0x1234, -0x800, 1, 0, 7)   // Testcase 10
	TEST_IMM_OP(addi, 11, 20, 0x0000000080000000, 0x80000000, 0x0, 1, 4, 7)   // Testcase 11
	TEST_IMM_OP(addi, 12, 19, 0xfffffffffffff5cb, -0x1234, 0x7ff, 1, 8, 7)   // Testcase 12
	TEST_IMM_OP(addi, 13, 18, 0xfffffffffffffffe, -0x1, -0x1, 1, 12, 7)   // Testcase 13
	TEST_IMM_OP(addi, 14, 17, 0xfffffffffffff802, -0x7ff, 0x1, 1, 16, 7)   // Testcase 14
	TEST_IMM_OP(addi, 15, 16, 0x0000000000000000, 0x0, 0x0, 2, 0, 3)   // Testcase 15
	TEST_IMM_OP(addi, 16, 15, 0xffffffffffffffff, -0x1, 0x0, 2, 4, 3)   // Testcase 16
	TEST_IMM_OP(addi, 17, 14, 0xfffffffffffff802, 0x1, -0x7ff, 2, 8, 3)   // Testcase 17
	TEST_IMM_OP(addi, 18, 13, 0xffffffffffffffff, 0x0, -0x1, 2, 12, 3)   // Testcase 18
	TEST_IMM_OP(addi, 19, 12, 0xffffffffffffffff, 0x7ff, -0x800, 2, 16, 3)   // Testcase 19
	TEST_IMM_OP(addi, 20, 11, 0xfffffffffffff800, 0x0, -0x800, 1, 0, 2)   // Testcase 20
	TEST_IMM_OP(addi, 21, 10, 0x0000000000000000, 0x800, -0x800, 1, 4, 2)   // Testcase 21
	TEST_IMM_OP(addi, 22,  9, 0x0000000007653b21, 0x7654321, -0x800, 1, 8, 2)   // Testcase 22
	TEST_IMM_OP(addi, 23,  8, 0x0000000080000000, 0x7fffffff, 0x1, 1, 12, 2)   // Testcase 23
	TEST_IMM_OP(addi, 24,  7, 0xfffffffffffff801, 0x1, -0x800, 1, 16, 2)   // Testcase 24
	TEST_IMM_OP(addi, 25,  6, 0xfffffffffffff7ff, 0xffffffffffffffff, -0x800, 1, 0, 7)   // Testcase 25
	TEST_IMM_OP(addi, 26,  5, 0x0000000000000a34, 0x1234, -0x800, 1, 4, 7)   // Testcase 26
	TEST_IMM_OP(addi, 27,  4, 0x0000000080000000, 0x80000000, 0x0, 1, 8, 7)   // Testcase 27
	TEST_IMM_OP(addi, 28,  3, 0xfffffffffffff5cb, -0x1234, 0x7ff, 1, 12, 7)   // Testcase 28
	TEST_IMM_OP(addi, 29,  2, 0xfffffffffffffffe, -0x1, -0x1, 1, 16, 7)   // Testcase 29
	TEST_IMM_OP(addi, 30,  1, 0xfffffffffffff802, -0x7ff, 0x1, 2, 0, 3)   // Testcase 30
	TEST_IMM_OP(addi, 31,  0, 0x0000000000000000, 0x0, 0x0, 2, 4, 3)   // Testcase 31

	TEST_IMM_OP(andi,  0, 31, 0x0000000000000000, -0x1, 0x0, 5, 0, 6)   // Testcase 0
	TEST_IMM_OP(andi,  1, 30, 0x0000000000000001, 0x1, -0x7ff, 5, 4, 6)   // Testcase 1
	TEST_IMM_OP(andi,  2, 29, 0x0000000000000000, 0x0, -0x1, 5, 8, 6)   // Testcase 2
	TEST_IMM_OP(andi,  3, 28, 0x0000000000000000, 0x7ff, -0x800, 5, 12, 6)   // Testcase 3
	TEST_IMM_OP(andi,  4, 27, 0x0000000000000000, 0x0, -0x800, 5, 16, 6)   // Testcase 4
	TEST_IMM_OP(andi,  5, 26, 0x0000000000000800, 0x800, -0x800, 1, 0, 2)   // Testcase 5
	TEST_IMM_OP(andi,  6, 25, 0x0000000007654000, 0x7654321, -0x800, 1, 4, 2)   // Testcase 6
	TEST_IMM_OP(andi,  7, 24, 0x0000000000000001, 0x7fffffff, 0x1, 1, 8, 2)   // Testcase 7
	TEST_IMM_OP(andi,  8, 23, 0x0000000000000000, 0x1, -0x800, 1, 12, 2)   // Testcase 8
	TEST_IMM_OP(andi,  9, 22, 0xfffffffffffff800, 0xffffffffffffffff, -0x800, 1, 16, 2)   // Testcase 9
	TEST_IMM_OP(andi, 10, 21, 0x0000000000001000, 0x1234, -0x800, 1, 0, 7)   // Testcase 10
	TEST_IMM_OP(andi, 11, 20, 0x0000000000000000, 0x80000000, 0x0, 1, 4, 7)   // Testcase 11
	TEST_IMM_OP(andi, 12, 19, 0x00000000000005cc, -0x1234, 0x7ff, 1, 8, 7)   // Testcase 12
	TEST_IMM_OP(andi, 13, 18, 0xffffffffffffffff, -0x1, -0x1, 1, 12, 7)   // Testcase 13
	TEST_IMM_OP(andi, 14, 17, 0x0000000000000001, -0x7ff, 0x1, 1, 16, 7)   // Testcase 14
	TEST_IMM_OP(andi, 15, 16, 0x0000000000000000, 0x0, 0x0, 2, 0, 3)   // Testcase 15
	TEST_IMM_OP(andi, 16, 15, 0x0000000000000000, -0x1, 0x0, 2, 4, 3)   // Testcase 16
	TEST_IMM_OP(andi, 17, 14, 0x0000000000000001, 0x1, -0x7ff, 2, 8, 3)   // Testcase 17
	TEST_IMM_OP(andi, 18, 13, 0x0000000000000000, 0x0, -0x1, 2, 12, 3)   // Testcase 18
	TEST_IMM_OP(andi, 19, 12, 0x0000000000000000, 0x7ff, -0x800, 2, 16, 3)   // Testcase 19
	TEST_IMM_OP(andi, 20, 11, 0x0000000000000000, 0x0, -0x800, 1, 0, 2)   // Testcase 20
	TEST_IMM_OP(andi, 21, 10, 0x0000000000000800, 0x800, -0x800, 1, 4, 2)   // Testcase 21
	TEST_IMM_OP(andi, 22,  9, 0x0000000007654000, 0x7654321, -0x800, 1, 8, 2)   // Testcase 22
	TEST_IMM_OP(andi, 23,  8, 0x0000000000000001, 0x7fffffff, 0x1, 1, 12, 2)   // Testcase 23
	TEST_IMM_OP(andi, 24,  7, 0x0000000000000000, 0x1, -0x800, 1, 16, 2)   // Testcase 24
	TEST_IMM_OP(andi, 25,  6, 0x00000000fffff800, 0xffffffff, -0x800, 1, 0, 7)   // Testcase 25
	TEST_IMM_OP(andi, 26,  5, 0x0000000000001000, 0x1234, -0x800, 1, 4, 7)   // Testcase 26
	TEST_IMM_OP(andi, 27,  4, 0x0000000000000000, 0x80000000, 0x0, 1, 8, 7)   // Testcase 27
	TEST_IMM_OP(andi, 28,  3, 0x00000000000005cc, -0x1234, 0x7ff, 1, 12, 7)   // Testcase 28
	TEST_IMM_OP(andi, 29,  2, 0xffffffffffffffff, -0x1, -0x1, 1, 16, 7)   // Testcase 29
	TEST_IMM_OP(andi, 30,  1, 0x0000000000000001, -0x7ff, 0x1, 2, 0, 3)   // Testcase 30
	TEST_IMM_OP(andi, 31,  0, 0x0000000000000000, 0x0, 0x0, 2, 4, 3)   // Testcase 31

	TEST_IMM_OP(ori,  0, 31, 0x0000000000000000, -0x1, 0x0, 5, 0, 6)   // Testcase 0
	TEST_IMM_OP(ori,  1, 30, 0xfffffffffffff801, 0x1, -0x7ff, 5, 4, 6)   // Testcase 1
	TEST_IMM_OP(ori,  2, 29, 0xffffffffffffffff, 0x0, -0x1, 5, 8, 6)   // Testcase 2
	TEST_IMM_OP(ori,  3, 28, 0xffffffffffffffff, 0x7ff, -0x800, 5, 12, 6)   // Testcase 3
	TEST_IMM_OP(ori,  4, 27, 0xfffffffffffff800, 0x0, -0x800, 5, 16, 6)   // Testcase 4
	TEST_IMM_OP(ori,  5, 26, 0xfffffffffffff800, 0x800, -0x800, 1, 0, 2)   // Testcase 5
	TEST_IMM_OP(ori,  6, 25, 0xfffffffffffffb21, 0x7654321, -0x800, 1, 4, 2)   // Testcase 6
	TEST_IMM_OP(ori,  7, 24, 0x000000007fffffff, 0x7fffffff, 0x1, 1, 8, 2)   // Testcase 7
	TEST_IMM_OP(ori,  8, 23, 0xfffffffffffff801, 0x1, -0x800, 1, 12, 2)   // Testcase 8
	TEST_IMM_OP(ori,  9, 22, 0xffffffffffffffff, 0xffffffff, -0x800, 1, 16, 2)   // Testcase 9
	TEST_IMM_OP(ori, 10, 21, 0xfffffffffffffa34, 0x1234, -0x800, 1, 0, 7)   // Testcase 10
	TEST_IMM_OP(ori, 11, 20, 0x0000000080000000, 0x80000000, 0x0, 1, 4, 7)   // Testcase 11
	TEST_IMM_OP(ori, 12, 19, 0xffffffffffffefff, -0x1234, 0x7ff, 1, 8, 7)   // Testcase 12
	TEST_IMM_OP(ori, 13, 18, 0xffffffffffffffff, -0x1, -0x1, 1, 12, 7)   // Testcase 13
	TEST_IMM_OP(ori, 14, 17, 0xfffffffffffff801, -0x7ff, 0x1, 1, 16, 7)   // Testcase 14
	TEST_IMM_OP(ori, 15, 16, 0x0000000000000000, 0x0, 0x0, 2, 0, 3)   // Testcase 15
	TEST_IMM_OP(ori, 16, 15, 0xffffffffffffffff, -0x1, 0x0, 2, 4, 3)   // Testcase 16
	TEST_IMM_OP(ori, 17, 14, 0xfffffffffffff801, 0x1, -0x7ff, 2, 8, 3)   // Testcase 17
	TEST_IMM_OP(ori, 18, 13, 0xffffffffffffffff, 0x0, -0x1, 2, 12, 3)   // Testcase 18
	TEST_IMM_OP(ori, 19, 12, 0xffffffffffffffff, 0x7ff, -0x800, 2, 16, 3)   // Testcase 19
	TEST_IMM_OP(ori, 20, 11, 0xfffffffffffff800, 0x0, -0x800, 1, 0, 2)   // Testcase 20
	TEST_IMM_OP(ori, 21, 10, 0xfffffffffffff800, 0x800, -0x800, 1, 4, 2)   // Testcase 21
	TEST_IMM_OP(ori, 22,  9, 0xfffffffffffffb21, 0x7654321, -0x800, 1, 8, 2)   // Testcase 22
	TEST_IMM_OP(ori, 23,  8, 0x000000007fffffff, 0x7fffffff, 0x1, 1, 12, 2)   // Testcase 23
	TEST_IMM_OP(ori, 24,  7, 0xfffffffffffff801, 0x1, -0x800, 1, 16, 2)   // Testcase 24
	TEST_IMM_OP(ori, 25,  6, 0xffffffffffffffff, 0xffffffff, -0x800, 1, 0, 7)   // Testcase 25
	TEST_IMM_OP(ori, 26,  5, 0xfffffffffffffa34, 0x1234, -0x800, 1, 4, 7)   // Testcase 26
	TEST_IMM_OP(ori, 27,  4, 0x0000000080000000, 0x80000000, 0x0, 1, 8, 7)   // Testcase 27
	TEST_IMM_OP(ori, 28,  3, 0xffffffffffffefff, -0x1234, 0x7ff, 1, 12, 7)   // Testcase 28
	TEST_IMM_OP(ori, 29,  2, 0xffffffffffffffff, -0x1, -0x1, 1, 16, 7)   // Testcase 29
	TEST_IMM_OP(ori, 30,  1, 0xfffffffffffff801, -0x7ff, 0x1, 2, 0, 3)   // Testcase 30
	TEST_IMM_OP(ori, 31,  0, 0x0000000000000000, 0x0, 0x0, 2, 4, 3)   // Testcase 31

	TEST_IMM_OP(slli,  0, 31, 0x0000000000000000, -0x1, 0x0, 5, 0, 6)   // Testcase 0
	TEST_IMM_OP(slli,  1, 30, 0x0000000000000001, 0x1, 0x0, 5, 4, 6)   // Testcase 1
	TEST_IMM_OP(slli,  2, 29, 0x0000000000000000, 0x0, 0x1, 5, 8, 6)   // Testcase 2
	TEST_IMM_OP(slli,  3, 28, 0x0000000000007ff0, 0x7ff, 0x4, 5, 12, 6)   // Testcase 3
	TEST_IMM_OP(slli,  4, 27, 0x0000000000000000, 0x0, 0x8, 5, 16, 6)   // Testcase 4
	TEST_IMM_OP(slli,  5, 26, 0x0000040000000000, 0x800, 0x1f, 1, 0, 2)   // Testcase 5
	TEST_IMM_OP(slli,  6, 25, 0x0000076543210000, 0x7654321, 0x10, 1, 4, 2)   // Testcase 6
	TEST_IMM_OP(slli,  7, 24, 0x00000000fffffffe, 0x7fffffff, 0x1, 1, 8, 2)   // Testcase 7
	TEST_IMM_OP(slli,  8, 23, 0x0000000000000001, 0x1, 0x0, 1, 12, 2)   // Testcase 8
	TEST_IMM_OP(slli,  9, 22, 0x00000000ffffffff, 0xffffffff, 0x0, 1, 16, 2)   // Testcase 9
	TEST_IMM_OP(slli, 10, 21, 0x0000000000002468, 0x1234, 0x1, 1, 0, 7)   // Testcase 10
	TEST_IMM_OP(slli, 11, 20, 0x0000000800000000, 0x80000000, 0x4, 1, 4, 7)   // Testcase 11
	TEST_IMM_OP(slli, 12, 19, 0xffffffffffedcc00, -0x1234, 0x8, 1, 8, 7)   // Testcase 12
	TEST_IMM_OP(slli, 13, 18, 0xffffffff80000000, -0x1, 0x1f, 1, 12, 7)   // Testcase 13
	TEST_IMM_OP(slli, 14, 17, 0xfffffffff8010000, -0x7ff, 0x10, 1, 16, 7)   // Testcase 14
	TEST_IMM_OP(slli, 15, 16, 0x0000000000000000, 0x0, 0x1, 2, 0, 3)   // Testcase 15
	TEST_IMM_OP(slli, 16, 15, 0xffffffffffffffff, -0x1, 0x0, 2, 4, 3)   // Testcase 16
	TEST_IMM_OP(slli, 17, 14, 0x0000000000000001, 0x1, 0x0, 2, 8, 3)   // Testcase 17
	TEST_IMM_OP(slli, 18, 13, 0x0000000000000000, 0x0, 0x1, 2, 12, 3)   // Testcase 18
	TEST_IMM_OP(slli, 19, 12, 0x0000000000007ff0, 0x7ff, 0x4, 2, 16, 3)   // Testcase 19
	TEST_IMM_OP(slli, 20, 11, 0x0000000000000000, 0x0, 0x8, 1, 0, 2)   // Testcase 20
	TEST_IMM_OP(slli, 21, 10, 0x0000040000000000, 0x800, 0x1f, 1, 4, 2)   // Testcase 21
	TEST_IMM_OP(slli, 22,  9, 0x0000076543210000, 0x7654321, 0x10, 1, 8, 2)   // Testcase 22
	TEST_IMM_OP(slli, 23,  8, 0x00000000fffffffe, 0x7fffffff, 0x1, 1, 12, 2)   // Testcase 23
	TEST_IMM_OP(slli, 24,  7, 0x0000000000000001, 0x1, 0x0, 1, 16, 2)   // Testcase 24
	TEST_IMM_OP(slli, 25,  6, 0x00000000ffffffff, 0xffffffff, 0x0, 1, 0, 7)   // Testcase 25
	TEST_IMM_OP(slli, 26,  5, 0x0000000000002468, 0x1234, 0x1, 1, 4, 7)   // Testcase 26
	TEST_IMM_OP(slli, 27,  4, 0x0000000800000000, 0x80000000, 0x4, 1, 8, 7)   // Testcase 27
	TEST_IMM_OP(slli, 28,  3, 0xffffffffffedcc00, -0x1234, 0x8, 1, 12, 7)   // Testcase 28
	TEST_IMM_OP(slli, 29,  2, 0xffffffff80000000, -0x1, 0x1f, 1, 16, 7)   // Testcase 29
	TEST_IMM_OP(slli, 30,  1, 0xfffffffff8010000, -0x7ff, 0x10, 2, 0, 3)   // Testcase 30
	TEST_IMM_OP(slli, 31,  0, 0x0000000000000000, 0x0, 0x1, 2, 4, 3)   // Testcase 31

	TEST_IMM_OP(slti, 0, 31, 0x0, -0x1, 0x0, 5, 0, 6)   // Testcase 0
	TEST_IMM_OP(slti, 1, 30, 0x0, 0x1, -0x7ff, 5, 4, 6)   // Testcase 1
	TEST_IMM_OP(slti, 2, 29, 0x0, 0x0, -0x1, 5, 8, 6)   // Testcase 2
	TEST_IMM_OP(slti, 3, 28, 0x0, 0x7ff, -0x800, 5, 12, 6)   // Testcase 3
	TEST_IMM_OP(slti, 4, 27, 0x0, 0x0, -0x800, 5, 16, 6)   // Testcase 4
	TEST_IMM_OP(slti, 5, 26, 0x0, 0x800, -0x800, 1, 0, 2)   // Testcase 5
	TEST_IMM_OP(slti, 6, 25, 0x0, 0x7654321, -0x800, 1, 4, 2)   // Testcase 6
	TEST_IMM_OP(slti, 7, 24, 0x0, 0x7fffffff, 0x1, 1, 8, 2)   // Testcase 7
	TEST_IMM_OP(slti, 8, 23, 0x0, 0x1, -0x800, 1, 12, 2)   // Testcase 8
	TEST_IMM_OP(slti, 9, 22, 0x0, 0xffffffff, -0x800, 1, 16, 2)   // Testcase 9
	TEST_IMM_OP(slti, 10, 21, 0x0, 0x1234, -0x800, 1, 0, 7)   // Testcase 10
	TEST_IMM_OP(slti, 11, 20, 0x1, (0x1ul << (__riscv_xlen - 1)), 0x0, 1, 4, 7)   // Testcase 11
	TEST_IMM_OP(slti, 12, 19, 0x1, -0x1234, 0x7ff, 1, 8, 7)   // Testcase 12
	TEST_IMM_OP(slti, 13, 18, 0x0, -0x1, -0x1, 1, 12, 7)   // Testcase 13
	TEST_IMM_OP(slti, 14, 17, 0x1, -0x7ff, 0x1, 1, 16, 7)   // Testcase 14
	TEST_IMM_OP(slti, 15, 16, 0x0, 0x0, 0x0, 2, 0, 3)   // Testcase 15
	TEST_IMM_OP(slti, 16, 15, 0x1, -0x1, 0x0, 2, 4, 3)   // Testcase 16
	TEST_IMM_OP(slti, 17, 14, 0x0, 0x1, -0x7ff, 2, 8, 3)   // Testcase 17
	TEST_IMM_OP(slti, 18, 13, 0x0, 0x0, -0x1, 2, 12, 3)   // Testcase 18
	TEST_IMM_OP(slti, 19, 12, 0x0, 0x7ff, -0x800, 2, 16, 3)   // Testcase 19
	TEST_IMM_OP(slti, 20, 11, 0x0, 0x0, -0x800, 1, 0, 2)   // Testcase 20
	TEST_IMM_OP(slti, 21, 10, 0x0, 0x800, -0x800, 1, 4, 2)   // Testcase 21
	TEST_IMM_OP(slti, 22, 9, 0x0, 0x7654321, -0x800, 1, 8, 2)   // Testcase 22
	TEST_IMM_OP(slti, 23, 8, 0x0, 0x7fffffff, 0x1, 1, 12, 2)   // Testcase 23
	TEST_IMM_OP(slti, 24, 7, 0x0, 0x1, -0x800, 1, 16, 2)   // Testcase 24
	TEST_IMM_OP(slti, 25, 6, 0x0, 0xffffffff, -0x800, 1, 0, 7)   // Testcase 25
	TEST_IMM_OP(slti, 26, 5, 0x0, 0x1234, -0x800, 1, 4, 7)   // Testcase 26
	TEST_IMM_OP(slti, 27, 4, 0x1, (0x1ul << (__riscv_xlen - 1)), 0x0, 1, 8, 7)   // Testcase 27
	TEST_IMM_OP(slti, 28, 3, 0x1, -0x1234, 0x7ff, 1, 12, 7)   // Testcase 28
	TEST_IMM_OP(slti, 29, 2, 0x0, -0x1, -0x1, 1, 16, 7)   // Testcase 29
	TEST_IMM_OP(slti, 30, 1, 0x1, -0x7ff, 0x1, 2, 0, 3)   // Testcase 30
	TEST_IMM_OP(slti, 31, 0, 0x0, 0x0, 0x0, 2, 4, 3)   // Testcase 31

	TEST_IMM_OP(sltiu,  0, 31, 0x0, -0x1, 0x0, 5, 0, 6)   // Testcase 0
	TEST_IMM_OP(sltiu,  1, 30, 0x1, 0x1, -0x7ff, 5, 4, 6)   // Testcase 1
	TEST_IMM_OP(sltiu,  2, 29, 0x1, 0x0, -0x1, 5, 8, 6)   // Testcase 2
	TEST_IMM_OP(sltiu,  3, 28, 0x1, 0x7ff, -0x800, 5, 12, 6)   // Testcase 3
	TEST_IMM_OP(sltiu,  4, 27, 0x1, 0x0, -0x800, 5, 16, 6)   // Testcase 4
	TEST_IMM_OP(sltiu,  5, 26, 0x1, 0x800, -0x800, 1, 0, 2)   // Testcase 5
	TEST_IMM_OP(sltiu,  6, 25, 0x1, 0x7654321, -0x800, 1, 4, 2)   // Testcase 6
	TEST_IMM_OP(sltiu,  7, 24, 0x0, 0x7fffffff, 0x1, 1, 8, 2)   // Testcase 7
	TEST_IMM_OP(sltiu,  8, 23, 0x1, 0x1, -0x800, 1, 12, 2)   // Testcase 8
	TEST_IMM_OP(sltiu,  9, 22, 0x0, 0xffffffff, -0x800, 1, 16, 2)   // Testcase 9
	TEST_IMM_OP(sltiu, 10, 21, 0x1, 0x1234, -0x800, 1, 0, 7)   // Testcase 10
	TEST_IMM_OP(sltiu, 11, 20, 0x0, 0x80000000, 0x0, 1, 4, 7)   // Testcase 11
	TEST_IMM_OP(sltiu, 12, 19, 0x0, -0x1234, 0x7ff, 1, 8, 7)   // Testcase 12
	TEST_IMM_OP(sltiu, 13, 18, 0x0, -0x1, -0x1, 1, 12, 7)   // Testcase 13
	TEST_IMM_OP(sltiu, 14, 17, 0x0, -0x7ff, 0x1, 1, 16, 7)   // Testcase 14
	TEST_IMM_OP(sltiu, 15, 16, 0x0, 0x0, 0x0, 2, 0, 3)   // Testcase 15
	TEST_IMM_OP(sltiu, 16, 15, 0x0, -0x1, 0x0, 2, 4, 3)   // Testcase 16
	TEST_IMM_OP(sltiu, 17, 14, 0x1, 0x1, -0x7ff, 2, 8, 3)   // Testcase 17
	TEST_IMM_OP(sltiu, 18, 13, 0x1, 0x0, -0x1, 2, 12, 3)   // Testcase 18
	TEST_IMM_OP(sltiu, 19, 12, 0x1, 0x7ff, -0x800, 2, 16, 3)   // Testcase 19
	TEST_IMM_OP(sltiu, 20, 11, 0x1, 0x0, -0x800, 1, 0, 2)   // Testcase 20
	TEST_IMM_OP(sltiu, 21, 10, 0x1, 0x800, -0x800, 1, 4, 2)   // Testcase 21
	TEST_IMM_OP(sltiu, 22,  9, 0x1, 0x7654321, -0x800, 1, 8, 2)   // Testcase 22
	TEST_IMM_OP(sltiu, 23,  8, 0x0, 0x7fffffff, 0x1, 1, 12, 2)   // Testcase 23
	TEST_IMM_OP(sltiu, 24,  7, 0x1, 0x1, -0x800, 1, 16, 2)   // Testcase 24
	TEST_IMM_OP(sltiu, 25,  6, 0x0, 0xffffffff, -0x800, 1, 0, 7)   // Testcase 25
	TEST_IMM_OP(sltiu, 26,  5, 0x1, 0x1234, -0x800, 1, 4, 7)   // Testcase 26
	TEST_IMM_OP(sltiu, 27,  4, 0x0, 0x80000000, 0x0, 1, 8, 7)   // Testcase 27
	TEST_IMM_OP(sltiu, 28,  3, 0x0, -0x1234, 0x7ff, 1, 12, 7)   // Testcase 28
	TEST_IMM_OP(sltiu, 29,  2, 0x0, -0x1, -0x1, 1, 16, 7)   // Testcase 29
	TEST_IMM_OP(sltiu, 30,  1, 0x0, -0x7ff, 0x1, 2, 0, 3)   // Testcase 30
	TEST_IMM_OP(sltiu, 31,  0, 0x0, 0x0, 0x0, 2, 4, 3)   // Testcase 31

	TEST_IMM_OP(srai,  0, 31, 0x0000000000000000, -0x1, 0x0, 5, 0, 6)   // Testcase 0
	TEST_IMM_OP(srai,  1, 30, 0x0000000000000001, 0x1, 0x0, 5, 4, 6)   // Testcase 1
	TEST_IMM_OP(srai,  2, 29, 0x0000000000000000, 0x0, 0x1, 5, 8, 6)   // Testcase 2
	TEST_IMM_OP(srai,  3, 28, 0x000000000000007f, 0x7ff, 0x4, 5, 12, 6)   // Testcase 3
	TEST_IMM_OP(srai,  4, 27, 0x0000000000000000, 0x0, 0x8, 5, 16, 6)   // Testcase 4
	TEST_IMM_OP(srai,  5, 26, 0x0000000000000000, 0x800, 0x1f, 1, 0, 2)   // Testcase 5
	TEST_IMM_OP(srai,  6, 25, 0x0000000000000765, 0x7654321, 0x10, 1, 4, 2)   // Testcase 6
	TEST_IMM_OP(srai,  7, 24, 0x000000003fffffff, 0x7fffffff, 0x1, 1, 8, 2)   // Testcase 7
	TEST_IMM_OP(srai,  8, 23, 0x0000000000000001, 0x1, 0x0, 1, 12, 2)   // Testcase 8
	TEST_IMM_OP(srai,  9, 22, 0xffffffffffffffff, 0xffffffffffffffff, 0x0, 1, 16, 2)   // Testcase 9
	TEST_IMM_OP(srai, 10, 21, 0x000000000000091a, 0x1234, 0x1, 1, 0, 7)   // Testcase 10
	TEST_IMM_OP(srai, 11, 20, 0xfffffffff8000000, 0xffffffff80000000, 0x4, 1, 4, 7)   // Testcase 11
	TEST_IMM_OP(srai, 12, 19, 0xffffffffffffffed, -0x1234, 0x8, 1, 8, 7)   // Testcase 12
	TEST_IMM_OP(srai, 13, 18, 0xffffffffffffffff, -0x1, 0x1f, 1, 12, 7)   // Testcase 13
	TEST_IMM_OP(srai, 14, 17, 0xffffffffffffffff, -0x7ff, 0x10, 1, 16, 7)   // Testcase 14
	TEST_IMM_OP(srai, 15, 16, 0x0000000000000000, 0x0, 0x1, 2, 0, 3)   // Testcase 15
	TEST_IMM_OP(srai, 16, 15, 0xffffffffffffffff, -0x1, 0x0, 2, 4, 3)   // Testcase 16
	TEST_IMM_OP(srai, 17, 14, 0x0000000000000001, 0x1, 0x0, 2, 8, 3)   // Testcase 17
	TEST_IMM_OP(srai, 18, 13, 0x0000000000000000, 0x0, 0x1, 2, 12, 3)   // Testcase 18
	TEST_IMM_OP(srai, 19, 12, 0x000000000000007f, 0x7ff, 0x4, 2, 16, 3)   // Testcase 19
	TEST_IMM_OP(srai, 20, 11, 0x0000000000000000, 0x0, 0x8, 1, 0, 2)   // Testcase 20
	TEST_IMM_OP(srai, 21, 10, 0x0000000000000000, 0x800, 0x1f, 1, 4, 2)   // Testcase 21
	TEST_IMM_OP(srai, 22,  9, 0x0000000000000765, 0x7654321, 0x10, 1, 8, 2)   // Testcase 22
	TEST_IMM_OP(srai, 23,  8, 0x000000003fffffff, 0x7fffffff, 0x1, 1, 12, 2)   // Testcase 23
	TEST_IMM_OP(srai, 24,  7, 0x0000000000000001, 0x1, 0x0, 1, 16, 2)   // Testcase 24
	TEST_IMM_OP(srai, 25,  6, 0xffffffffffffffff, 0xffffffffffffffff, 0x0, 1, 0, 7)   // Testcase 25
	TEST_IMM_OP(srai, 26,  5, 0x000000000000091a, 0x1234, 0x1, 1, 4, 7)   // Testcase 26
	TEST_IMM_OP(srai, 27,  4, 0xfffffffff8000000, 0xffffffff80000000, 0x4, 1, 8, 7)   // Testcase 27
	TEST_IMM_OP(srai, 28,  3, 0xffffffffffffffed, -0x1234, 0x8, 1, 12, 7)   // Testcase 28
	TEST_IMM_OP(srai, 29,  2, 0xffffffffffffffff, -0x1, 0x1f, 1, 16, 7)   // Testcase 29
	TEST_IMM_OP(srai, 30,  1, 0xffffffffffffffff, -0x7ff, 0x10, 2, 0, 3)   // Testcase 30
	TEST_IMM_OP(srai, 31,  0, 0x0000000000000000, 0x0, 0x1, 2, 4, 3)   // Testcas e 31

	TEST_IMM_OP(srli,  0, 31, 0x0000000000000000, -0x1, 0x0, 5, 0, 6)   // Testcase 0
	TEST_IMM_OP(srli,  1, 30, 0x0000000000000001, 0x1, 0x0, 5, 4, 6)   // Testcase 1
	TEST_IMM_OP(srli,  2, 29, 0x0000000000000000, 0x0, 0x1, 5, 8, 6)   // Testcase 2
	TEST_IMM_OP(srli,  3, 28, 0x000000000000007f, 0x7ff, 0x4, 5, 12, 6)   // Testcase 3
	TEST_IMM_OP(srli,  4, 27, 0x0000000000000000, 0x0, 0x8, 5, 16, 6)   // Testcase 4
	TEST_IMM_OP(srli,  5, 26, 0x0000000000000000, 0x800, 0x1f, 1, 0, 2)   // Testcase 5
	TEST_IMM_OP(srli,  6, 25, 0x0000000000000765, 0x7654321, 0x10, 1, 4, 2)   // Testcase 6
	TEST_IMM_OP(srli,  7, 24, 0x000000003fffffff, 0x7fffffff, 0x1, 1, 8, 2)   // Testcase 7
	TEST_IMM_OP(srli,  8, 23, 0x0000000000000001, 0x1, 0x0, 1, 12, 2)   // Testcase 8
	TEST_IMM_OP(srli,  9, 22, 0x00000000ffffffff, 0xffffffff, 0x0, 1, 16, 2)   // Testcase 9
	TEST_IMM_OP(srli, 10, 21, 0x000000000000091a, 0x1234, 0x1, 1, 0, 7)   // Testcase 10
	TEST_IMM_OP(srli, 11, 20, 0x0000000008000000, 0x80000000, 0x4, 1, 4, 7)   // Testcase 11
#if USING_RV32
	TEST_IMM_OP(srli, 12, 19, 0x0000000000ffffed, -0x1234, 0x8, 1, 8, 7)   // Testcase 12
#else
	TEST_IMM_OP(srli, 12, 19, 0x00ffffffffffffed, -0x1234, 0x8, 1, 8, 7)   // Testcase 12
#endif
	TEST_IMM_OP(srli, 13, 18, UPPER(0x00000001ffffffff), -0x1, 0x1f, 1, 12, 7)   // Testcase 13
	TEST_IMM_OP(srli, 14, 17, UPPER(0x0000ffffffffffff), -0x7ff, 0x10, 1, 16, 7)   // Testcase 14
	TEST_IMM_OP(srli, 15, 16, 0x0000000000000000, 0x0, 0x1, 2, 0, 3)   // Testcase 15
	TEST_IMM_OP(srli, 16, 15, 0xffffffffffffffff, -0x1, 0x0, 2, 4, 3)   // Testcase 16
	TEST_IMM_OP(srli, 17, 14, 0x0000000000000001, 0x1, 0x0, 2, 8, 3)   // Testcase 17
	TEST_IMM_OP(srli, 18, 13, 0x0000000000000000, 0x0, 0x1, 2, 12, 3)   // Testcase 18
	TEST_IMM_OP(srli, 19, 12, 0x000000000000007f, 0x7ff, 0x4, 2, 16, 3)   // Testcase 19
	TEST_IMM_OP(srli, 20, 11, 0x0000000000000000, 0x0, 0x8, 1, 0, 2)   // Testcase 20
	TEST_IMM_OP(srli, 21, 10, 0x0000000000000000, 0x800, 0x1f, 1, 4, 2)   // Testcase 21
	TEST_IMM_OP(srli, 22,  9, 0x0000000000000765, 0x7654321, 0x10, 1, 8, 2)   // Testcase 22
	TEST_IMM_OP(srli, 23,  8, 0x000000003fffffff, 0x7fffffff, 0x1, 1, 12, 2)   // Testcase 23
	TEST_IMM_OP(srli, 24,  7, 0x0000000000000001, 0x1, 0x0, 1, 16, 2)   // Testcase 24
	TEST_IMM_OP(srli, 25,  6, 0x00000000ffffffff, 0xffffffff, 0x0, 1, 0, 7)   // Testcase 25
	TEST_IMM_OP(srli, 26,  5, 0x000000000000091a, 0x1234, 0x1, 1, 4, 7)   // Testcase 26
	TEST_IMM_OP(srli, 27,  4, 0x0000000008000000, 0x80000000, 0x4, 1, 8, 7)   // Testcase 27
#if USING_RV32
	TEST_IMM_OP(srli, 28,  3, 0x0000000000ffffed, -0x1234, 0x8, 1, 12, 7)   // Testcase 28
#else
	TEST_IMM_OP(srli, 28,  3, 0x00ffffffffffffed, -0x1234, 0x8, 1, 12, 7)   // Testcase 28
#endif
	TEST_IMM_OP(srli, 29,  2, UPPER(0x00000001ffffffff), -0x1, 0x1f, 1, 16, 7)   // Testcase 29
	TEST_IMM_OP(srli, 30,  1, UPPER(0x0000ffffffffffff), -0x7ff, 0x10, 2, 0, 3)   // Testcase 30
	TEST_IMM_OP(srli, 31,  0, 0x0000000000000000, 0x0, 0x1, 2, 4, 3)   // Testcase 31

	TEST_IMM_OP(xori,  0, 31, 0x0000000000000000, -0x1, 0x0, 5, 0, 6)   // Testcase 0
	TEST_IMM_OP(xori,  1, 30, 0xfffffffffffff800, 0x1, -0x7ff, 5, 4, 6)   // Testcase 1
	TEST_IMM_OP(xori,  2, 29, 0xffffffffffffffff, 0x0, -0x1, 5, 8, 6)   // Testcase 2
	TEST_IMM_OP(xori,  3, 28, 0xffffffffffffffff, 0x7ff, -0x800, 5, 12, 6)   // Testcase 3
	TEST_IMM_OP(xori,  4, 27, 0xfffffffffffff800, 0x0, -0x800, 5, 16, 6)   // Testcase 4
	TEST_IMM_OP(xori,  5, 26, 0xfffffffffffff000, 0x800, -0x800, 1, 0, 2)   // Testcase 5
	TEST_IMM_OP(xori,  6, 25, 0xfffffffff89abb21, 0x7654321, -0x800, 1, 4, 2)   // Testcase 6
	TEST_IMM_OP(xori,  7, 24, 0x000000007ffffffe, 0x7fffffff, 0x1, 1, 8, 2)   // Testcase 7
	TEST_IMM_OP(xori,  8, 23, 0xfffffffffffff801, 0x1, -0x800, 1, 12, 2)   // Testcase 8
	TEST_IMM_OP(xori,  9, 22, 0xffffffff000007ff, 0xffffffff, -0x800, 1, 16, 2)   // Testcase 9
	TEST_IMM_OP(xori, 10, 21, 0xffffffffffffea34, 0x1234, -0x800, 1, 0, 7)   // Testcase 10
	TEST_IMM_OP(xori, 11, 20, 0x0000000080000000, 0x80000000, 0x0, 1, 4, 7)   // Testcase 11
	TEST_IMM_OP(xori, 12, 19, 0xffffffffffffea33, -0x1234, 0x7ff, 1, 8, 7)   // Testcase 12
	TEST_IMM_OP(xori, 13, 18, 0x0000000000000000, -0x1, -0x1, 1, 12, 7)   // Testcase 13
	TEST_IMM_OP(xori, 14, 17, 0xfffffffffffff800, -0x7ff, 0x1, 1, 16, 7)   // Testcase 14
	TEST_IMM_OP(xori, 15, 16, 0x0000000000000000, 0x0, 0x0, 2, 0, 3)   // Testcase 15
	TEST_IMM_OP(xori, 16, 15, 0xffffffffffffffff, -0x1, 0x0, 2, 4, 3)   // Testcase 16
	TEST_IMM_OP(xori, 17, 14, 0xfffffffffffff800, 0x1, -0x7ff, 2, 8, 3)   // Testcase 17
	TEST_IMM_OP(xori, 18, 13, 0xffffffffffffffff, 0x0, -0x1, 2, 12, 3)   // Testcase 18
	TEST_IMM_OP(xori, 19, 12, 0xffffffffffffffff, 0x7ff, -0x800, 2, 16, 3)   // Testcase 19
	TEST_IMM_OP(xori, 20, 11, 0xfffffffffffff800, 0x0, -0x800, 1, 0, 2)   // Testcase 20
	TEST_IMM_OP(xori, 21, 10, 0xfffffffffffff000, 0x800, -0x800, 1, 4, 2)   // Testcase 21
	TEST_IMM_OP(xori, 22,  9, 0xfffffffff89abb21, 0x7654321, -0x800, 1, 8, 2)   // Testcase 22
	TEST_IMM_OP(xori, 23,  8, 0x000000007ffffffe, 0x7fffffff, 0x1, 1, 12, 2)   // Testcase 23
	TEST_IMM_OP(xori, 24,  7, 0xfffffffffffff801, 0x1, -0x800, 1, 16, 2)   // Testcase 24
	TEST_IMM_OP(xori, 25,  6, 0x00000000000007ff, 0xffffffffffffffff, -0x800, 1, 0, 7)   // Testcase 25
	TEST_IMM_OP(xori, 26,  5, 0xffffffffffffea34, 0x1234, -0x800, 1, 4, 7)   // Testcase 26
	TEST_IMM_OP(xori, 27,  4, 0x0000000080000000, 0x80000000, 0x0, 1, 8, 7)   // Testcase 27
	TEST_IMM_OP(xori, 28,  3, 0xffffffffffffea33, -0x1234, 0x7ff, 1, 12, 7)   // Testcase 28
	TEST_IMM_OP(xori, 29,  2, 0x0000000000000000, -0x1, -0x1, 1, 16, 7)   // Testcase 29
	TEST_IMM_OP(xori, 30,  1, 0xfffffffffffff800, -0x7ff, 0x1, 2, 0, 3)   // Testcase 30
	TEST_IMM_OP(xori, 31,  0, 0x0000000000000000, 0x0, 0x0, 2, 4, 3)   // Testcase 31
