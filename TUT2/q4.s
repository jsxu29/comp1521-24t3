	.text

# x - $t0
# y - $t1

main:
	la 	$a0, prompt_str
	li 	$v0, 4
	syscall 

	li 	$v0, 5
	syscall 
	move 	$t0, $v0 

	mul	$t1, $t0, $t0

	li 	$v0, 1
	move 	$a0, $t1
	syscall

	li 	$v0, 11
	li 	$a0, '\n'
	syscall

	jr $ra

	.data
prompt_str: 
	.asciiz "Enter a number: "

