# code

# Assume that the variable s is implemented as register $t0
# and variable length is implemented as register $t1.
# the character '\0' can be represented by a value of zero.


	la 	$t0, string
	li	$t1, 1

loop_cond:
	# if *s == '\0', i.e. *s == 0, exit loop and jump to loop_post
	lb 	$t2, ($t0) 	# t2 stores *s
	beqz	$t2, loop_post

loop_body:
	# length++
	addi	$t1, $t1, 1

loop_step:
	# s++
	addi	$t0, $t0, 1
	j 	loop_cond

loop_post:



   	.data
string:
   	.asciiz "...."
