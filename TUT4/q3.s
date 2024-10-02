# Recursive maximum of array function

	# Register usage:
	# - `array' is in $a0 (only before function call)
	# - `length' is in $a1 (only before function call)
	# - `first_element' is in $s0
	# - `max_so_far' is in $t0 (only after function call)

	# $s0 used for first_element because it needs
	# to keep its value across recursive call

max:




	# some simple test code which calls max
main:
main__prologue:
	push	$ra

main__body:
	la	$a0, array
	li	$a1, 10
	jal	max			# result = max(array, 10)
					# use jal for jump and link, this saves the next line 
					# as our return address and then jumps to 
					# the specified location

	move	$a0, $v0
	li	$v0, 1			# syscall 1: print_int
	syscall				# printf("%d", result)

	li	$a0, '\n'
	li	$v0, 11			# syscall 11: print_char
	syscall				# printf("%c", '\n');

	li	$v0, 0

main__epilogue:
	pop	$ra
	jr	$ra			# return 0;


.data
array:
	.word 1, 2, 3, 4, 5, 6, 4, 3, 2, 1
