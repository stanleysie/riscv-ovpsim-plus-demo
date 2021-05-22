.globl main

.data
iteration: .word 50000
size: .word 16
var1: .word 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
var2: .word 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
var3: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
newline: .asciz "\n"

.macro NEWLINE
	la a0, newline
	li a7, 4
	ecall
.end_macro

.text
main:
lw t1, iteration

loop1:
	beqz t1, done
	lw t2, size
	la t4, var1
	la t5, var2
	la t6, var3
	j loop2

loop2:
	beqz t2, next
	lw x11, (t4)	# load value from var1
	lw x12, (t5)	# load value from var2
	mul x13, x11, x12
	sw x13, (t6)	# store value in var3
	
	addi t2, t2, -1	# decrement
	addi t4, t4, 4
	addi t5, t5, 4
	addi t6, t6, 4
	j loop2
	
next:
	add a0, zero, t1
	li a7, 1
	ecall
	NEWLINE
	addi t1, t1, -1
	j loop1

done:
