// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.
    
    /* GENERAL FOR LOOP STRUCTURE
    for (INITIALISATION; CONDITION; INCREMENT) {
        BODY
    }*/

    /* V1: original for loop version
    for (int x = 24; x < 42; x += 3) {
        printf("%d\n", x);
    }*/

    /* V2: conversion to while loop
    // INTIALISATION
    int x=24;
    // CONDITION
    while (x < 42) {
        //BODY
        printf("%d\n", x);
        // INCREMENT
        x += 3;
    }*/

    // V3: converting to labels and jump instructions
    int x = 24;

loop_cond:
    if (x >= 42) goto loop_end; 

loop_body:
    printf("%d\n", x);

loop_incr:
    x += 3; // x = x + 3
    
    goto loop_cond;

loop_end:
    return 0;
}
