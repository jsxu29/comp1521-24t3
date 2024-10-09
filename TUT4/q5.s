# Sum 4 numbers using function calls.
# Note the use of the stack to save $ra in main, 
# and $ra $a0, $a1, $s0 in sum2.
main:
	begin
	push	$ra


	li	$a0, 11
	li	$a1, 13
	li 	$a2, 17
	li	$a3, 19
	jal	sum4		# sum4(11, 13, 17, 19);

	# result - $v0
	move	$a0, $v0
	li	$v0, 1
	syscall			# printf("%d", result)

	li	$v0, 11
	li	$a0, '\n'
	syscall


	pop	$ra
	end

	li      $v0, 0          # return 0 from function main
        jr      $ra             # return from function main

# We use $s0 for 'e' because its value must survive a function call to sum4. 
# So by convention we must store $s0's original value on the stack, and then
# we can restore it before sum4 returns.
#
# Note sum2 is simple function which changes only $v0.
# We could simplify sum4 by relying on this, 
# but in general we don't do this.
# We assume only registers $s0..$s7 survive function calls
#

# Registers:
# a,b,c,d are in $a0,$a1,$a2,$a3
# res1 is in $s0, res2 is in $s1
# c and d are in $s2,$s3 to be preserved across calls
# Final return is in $v0

sum4:
	begin
	push	$ra
	push	$s0
	push	$s1
	push	$s2
	push	$s3

sum4__body:
	move	$s2, $a2
	move	$s3, $a3

	# a - $a0, b - $a1
	jal 	sum2		# res1 = sum2(a, b)
	move 	$s0, $v0	
	# res1 - $s0

	move	$a0, $s2
	move	$a1, $s3
	jal 	sum2
	move	$s1, $v0	# $s1 - res2 = sum2(c, d)

	move	$a0, $s0
	move	$a1, $s1
	jal 	sum2		# $v0 - sum2(res1, res2)

sum4__epilogue:
	pop	$s3
	pop	$s2
	pop	$s1
	pop	$s0
	pop	$ra
	end

	jr $ra



sum2: 
	add	$v0, $a0, $a1
	jr	$ra
