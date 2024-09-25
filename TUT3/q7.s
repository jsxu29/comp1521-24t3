main:
	# $t0 - i
	# $t1 - N_SIZE = 10

loop_init:
	li	$t0, 0
	li	$t1, 10

loop_cond:
	bge	$t0, $t1, loop_post	# exit loop if i >= N_SIZE

loop_body:
					# find address of numbers[i]
	mul	$t2, $t0, 4		# calculate offset
	la 	$t3, numbers
	add 	$t4, $t3, $t2 		# $t4 = address of numbers[i]

	lw	$t5, ($t4)		# $t5 = numbers[i]

	bge	$t5, 0, loop_step	# if numbers[i] >= 0, jump to loop_step
	addi	$t6, $t5, 42
	sw	$t6, ($t4)

loop_step:
	# extra instructions to print the value at numbers[i] to verify the program
	# lw	$t5, ($t4)
	# move 	$a0, $t5
	# li	$v0, 1
	# syscall

	# li 	$a0, '\n'
	# li	$v0, 11
	# syscall

	addi 	$t0, $t0, 1
	j	loop_cond

loop_post:

	li 	$v0, 0
	jr 	$ra

	.data
# put things in memory 
numbers: .word 	0, 1, 2, -3, 4, -5, 6, -7, 8, 9
