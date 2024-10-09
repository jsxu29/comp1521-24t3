# This program prints out a danish flag, by
# looping through the rows and columns of the flag.
# Each element inside the flag is a single character.
# (i.e., 1 byte).
#
# (Dette program udskriver et dansk flag, ved at
# sløjfe gennem rækker og kolonner i flaget.)
#

# Constants
FLAG_ROWS = 6
FLAG_COLS = 12

# Registers:
# - row in $t0
# - col in $t1
# - row offset in $t2
# - row+col offset in $t3
main:

row_loop__init:
	li	$t0, 0

row_loop__cond:
	bge 	$t0, FLAG_ROWS, row_loop__post

row_loop__body:

col_loop__init:
	li 	$t1, 0

col_loop__cond:
	bge	$t1, FLAG_COLS, col_loop__post

col_loop__body:

	mul 	$t2, FLAG_COLS, $t0	# row * 12
	add	$t3, $t2, $t1		# position of element - row * 12 + col

	mul	$t4, $t3, 1 		# multiplied by size of each array element -> offset

	la	$t5, flag
	add	$t5, $t5, $t4		# address of flag[row][col]

	lb	$t6, ($t5)

	li	$v0, 11			# printf("%c", flag[row][col]);
	move	$a0, $t6
	syscall

col_loop__step:
	addi	$t1, $t1, 1
	b	col_loop__cond

col_loop__post:

	li	$v0, 11
	li	$a0, '\n'
	syscall

row_loop__step:
	addi	$t0, $t0, 1
	b	row_loop__cond

row_loop__post:

	li	$v0, 0
	jr	$ra



.data

flag:
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'