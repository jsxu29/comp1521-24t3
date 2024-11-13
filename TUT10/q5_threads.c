// Write a C program that creates a thread that infinitely prints some message provided by main
// (eg. "Hello\n"), while the main (default) thread infinitely prints a different message
// (eg. "there!\n").

#include <stdio.h>
#include <pthread.h>

void *func(void *arg) {
    char *string = arg;
    while (1) {
        printf("%s", string);
    }
    return NULL;
}

int main() {
    char *thread_message = "Hello\n";
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &func, thread_message);

    while (1) {
        printf("there\n");
    }

    // waits for our thread that prints "there!\n" to terminate before terminating our program
    pthread_join(thread_id, NULL);
    return 0;
}