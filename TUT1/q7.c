#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 0; i < argc; i++) {
        // for every command line argument, convert it to an integer and add it to the sum
        sum += atoi(argv[i]);
        printf("%s has integer value %d\n", argv[i], atoi(argv[i]));
    }
    printf("sum of command-line arguments = %d\n", sum);
    return 0;
}
