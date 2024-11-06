#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // change permissions to be not publically writeable for all command line arguments
    // for loop
        // for each command line arg, change perms
        // get the mode of the file
        // check if publically writeable 
        // if not publically writeable -> print that it is not
        // if publically writeable -> change permissions to be not publically writeable, and then print

    for (int i = 1; i < argc; i++) {
        // argv[i] -> command line arg or file/directory name
        struct stat s;
        int output = stat(argv[i], &s);
        if (output != 0) {
            perror("unable to get file metadata");
            continue;
        }

        mode_t mode = s.st_mode;
        if ((mode & S_IWOTH) == 0) {
            printf("%s is not publically writable\n", argv[i]);
            continue;
        }

        // it is publically writeable, remove this permission
        // first make the mode we want
        //                   rwxr---w-
        // i.e. mode - 0b... 111100010
        //                 ^ 000000010
        //                   111100000
        mode = mode ^ S_IWOTH;

        if (chmod(argv[i], mode) != 0) {
            perror("unable to change permissions");
            continue;
        }

        printf("removing public write from %s\n", argv[i]);
    }

    return 0;
}
