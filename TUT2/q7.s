main:

loop_init:
	li	$t0, 24 

loop_cond:
	bge 	$t0, 42, loop_end

loop_body:
	li	$v0, 1
	move 	$a0, $t0
	syscall

	li 	$v0, 11
	li 	$a0, '\n'
	syscall

loop_incr:
	addi 	$t0, $t0, 3
	j 	loop_cond

loop_end:
	jr	$ra
