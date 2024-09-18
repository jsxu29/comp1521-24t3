#include <stdio.h>

int *get_num_ptr(int a);

int main(void) {
    int *num = get_num_ptr(1);
    num = get_num_ptr(2);
    printf("%d\n", *num);
}

int *get_num_ptr(int a) {
    int x = a;
    return &x;
}
