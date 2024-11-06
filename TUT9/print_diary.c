#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // $HOME    
    char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        home_dir = ".";
    }

    // get full pathname
    size_t len = strlen(home_dir) + strlen("/.diary") + 1;
    char *filename = malloc(len);
    if (snprintf(filename, len, "%s/.diary", home_dir) <= 0) {
        perror("unable to create filename");
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("unable to open file");
        return 1;
    }

    // print contents of $HOME/.diary
    char c;
    while ((c = fgetc(file)) != EOF) {
        fputc(c, stdout);
    }

    // cleanup
    free(filename);
    fclose(file);

    return 0;
}
