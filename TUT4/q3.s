# Recursive maximum of array function

	# Register usage:
	# - `array' is in $a0 (only before function call)
	# - `length' is in $a1 (only before function call)
	# - `first_element' is in $s0
	# - `max_so_far' is in $t0 (only after function call)

	# $s0 used for first_element because it needs
	# to keep its value across recursive call

max:

max__prologue:
	begin			# creates stack frame
	push	$ra		
	push	$s0		

max__body:
	# int first_element = array[0];
	lw	$s0, ($a0)

	beq	$a1, 1, max__base_case

# else statement
	# store the arguments
	addi	$a0, $a0, 4
	addi	$a1, $a1, -1
	jal	max		# max(&array[1], length - 1)

	# max_so_far - $v0
	bgt 	$s0, $v0, max__set_max

#else statement
	b	max__epilogue

#if statement
max__set_max:
	move	$v0, $s0
	b	max__epilogue

# if statement
max__base_case:
	# return first_element
	move	$v0, $s0 
	b 	max__epilogue

max__epilogue:
	pop	$s0 		# pop in reverse order
	pop	$ra
	end			# remove stack fram

	jr	$ra





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
