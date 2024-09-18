#include <stdio.h>

int main(void) {
    char str[10]; // - - - - - - - - - -
    str[0] = 'H'; // H - - - - - - - - -
    str[1] = 'i'; // H i - - - - - - - -
    printf("%s", str); // H i - - - - - - - -
    return 0;
}

