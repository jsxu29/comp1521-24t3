#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int global_total = 0;
// atomic operations - smallest possible operation -- assume this takes one step
// don't need to lock and unlock things ourselves
// but we can only use atomic operations

void *add_5000_to_counter(void *data) {
    for (int i = 0; i < 5000; i++) {
        // sleep for 1 nanosecond
        nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);

        // increment the global total by 1
        global_total++; // atomic operation
        // global_total += 1 - atomic
        // global_total = global_total + 1 - non-atomic
    }
    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // if program works correctly, should print 10000
    printf("Final total: %d\n", global_total);
}

/*{
    // this increment is atomic!
    my_atomic++;

    // this increment is atomic!
    my_atomic += 1;

    // this increment is NOT atomic!
    my_atomic = my_atomic + 1;
}*/