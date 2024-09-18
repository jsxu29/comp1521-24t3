// Prints the square of a number

#include <stdio.h>

int main(void) {
    int x, y; // declare variables

    printf("Enter a number: ");
    // put address of string inside $a0
    // put 4 into $v0
    // call syscall to print
    
    scanf("%d", &x);
    // put 5 into $v0
    // syscall
    // x our result is in $v0

    y = x * x;

    printf("%d\n", y);

    return 0;
}