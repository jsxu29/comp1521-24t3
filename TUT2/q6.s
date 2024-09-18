main:
	la 	$a0, prompt_str
	li 	$v0, 4
	syscall 
    
    li 	$v0, 5
	syscall 
	move 	$t0, $v0 

    ble     $t0, 100, else_branch
    bge     $t0, 1000, else_branch

    la 	$a0, medium_str
	li 	$v0, 4
	syscall 

    j   epilogue

else_branch:
    la 	$a0, small_big_str
	li 	$v0, 4
	syscall 

epilogue:

    jr $ra

	.data
prompt_str: 
	.asciiz "Enter a number: "
medium_str:
    .asciiz "medium\n"
small_big_str:
    .asciiz "small/big\n"
