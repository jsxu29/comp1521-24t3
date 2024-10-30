// Write a C program, fgrep.c, which is given 1+ command-line arguments which is
// a string to search for.
// If there is only 1 command-line argument it should read lines from stdin and
// print them to stdout if they contain the string specified as the first 
// command line argument.
//
// If there are 2 or more command line arguments, it should treat arguments 
// after the first as filenames and print any lines they contain which contain
// the string specified as the first command line arguments.
//
// When printing lines, preface them with their line number (indexed from 1).
//
// Print a suitable error message if there are not enough arguments, or there is
// an error opening a file.
//
// Example:
// ./fgrep hello nonexistentfile.txt
//  hello: nonexistentfile.txt: No such file or directory
//
// ./fgrep test testfile.txt
// line 1 from testfile.txt: This is a test
//
// Assume lines are 65536 bytes at most.

#include <stdio.h>
#include <string.h>

#define MAX_LINE 65536

void search_stream(FILE *stream, char stream_name[], char search_for[]);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prefix> <files>\n", argv[0]);
        return 1;
    } else if (argc == 2) {
        search_stream(stdin, "<stdin>", argv[1]);
    } else {

        for (int argument = 2; argument < argc; argument = argument + 1) {
            FILE *in = fopen(argv[argument], "r");
            // TODO: handle errors
            if (in == NULL) {
                printf("unable to open file %s", argv[argument]);
                continue;
            }

            search_stream(in, argv[argument], argv[1]);
            fclose(in);
        }

    }

    return 0;
}

void search_stream(FILE *stream, char stream_name[], char search_for[]) {
    // TODO: complete this function
    // hint: look at `strstr(3)'

    // given file, look for substring search_for
    // look at each line in file, for each line
    char line[MAX_LINE];
    int line_num = 1;

    while (fgets(line, MAX_LINE, stream) != NULL) {
        // check if the search_for is a substring of this line
        if(strstr(line, search_for) != NULL) {
            // if yes, print this line with a line number
            printf("line %d from %s: %s", line_num, stream_name, line);
        }
        line_num++;
    }
}
