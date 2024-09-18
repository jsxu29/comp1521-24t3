#include <stdio.h>

// argc - number of command line arguments, note: the object/execution file counts as a command line argument
// argv - array of strings/char pointer

// i.e. argv[0] = an address like 0x800000
// 0x800000 -> '.'
// 0x800001 -> '/'
// 0x800002 -> '.'
// 0x800003 -> 'a'
// 0x800004 -> .
// 0x800005 -> o
// 0x800006 -> u
// 0x800007 -> t
// 0x800008 -> '\0'

int main(int argc, char *argv[]) {
    printf("argc=%d\n", argc);

    // i = 0, 1, 2... argc - 1
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    return 0;
}
