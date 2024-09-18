#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    // 100 < x < 1000
    /*if (x > 100 && x < 1000) {
        printf("medium\n");
    } else {
        printf("small/big\n");
    }*/

// !(x > 100 && x < 1000)
// === !(x > 100) || !(x < 1000)
// === x <= 100 || x >= 1000

if (x <= 100) goto else_branch;
if (x >= 1000) goto else_branch;

    printf("medium\n");
    goto epilogue;

else_branch:
    printf("small/big\n");

epilogue:
    return 0;
}

