typedef unsigned int Word;

#include <assert.h>

// smaller example: 0101 -> 1010
// for each bit, get its value (whether its 0 or 1), and move it to the correct position

/* 
get the value for each bit

0101
1000 &
----
0000 == 0 

0101
0100 &
----
0100 != 0 -> 1

0101
0010 &
----
0000 == 0 -> 0

0101
0001 &
----
0001 != 0 -> 1
*/

/*
move it to the correct position

index: 0 1 2 3
       0 1 0 1

reversed word should have the order: 3 2 1 0

so, if you know there is a 1 at index 3, 
then there should be a 1 at index 0

0101 -> 1010
index in word vs index in reversed word:
<index in word> (<bit value>) -> <index in reversed word>
0 (0) -> 3
1 (1) -> 2
2 (0) -> 1
3 (1) -> 0

the pattern:
i -> (4 - 1) - i
i -> 3 - i

general pattern: i -> (n - 1) - i (where n is the number of bits)

to "add" the bit to the correct position, we can OR it with our result
i.e. 
res 0000
    1000 |
    ----
    1000

res 1000
    0000 |
    ----
    0000

res 1000
    0010 |
    ----
    1010

res 1010
    0000 |
    ----
    1010
*/

/* 
common strategy in questions

1. AND with a bit mask

mask is - 0 where we don't want the value, and 1 where we want to know what the bit value is, i.e. 0b1000

2. OR with our result to get all the bits in the right places

*/
Word reverseBits(Word w) {
    Word ret = 0;
    // assuming that word type / unsigned integers have 32 bits
    for (unsigned int bit = 0; bit < 32; bit++) {
        // get the value of the bit
        Word extractMask = 1 << bit;
        if (w & extractMask) {
            // move the 1 bit to the right position
            // i -> 31 - i
            Word keep = 1 << (31 - bit);
            ret |= keep; // ret = ret | keep;
            // a += b <=> a = a + b
        }
    }

    return ret;
}

// testing
int main(void) {
    Word w1 = 0x01234567;
    // 0000 => 0000 = 0
    // 0001 => 1000 = 8
    // 0010 => 0100 = 4
    // 0011 => 1100 = C
    // 0100 => 0010 = 2
    // 0101 => 1010 = A
    // 0110 => 0110 = 6
    // 0111 => 1110 = E
    assert(reverseBits(w1) == 0xE6A2C480);
    puts("All tests passed!");
    return 0;
}
