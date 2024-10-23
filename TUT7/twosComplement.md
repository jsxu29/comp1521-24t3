## Negative Integers

Last time we talked about representing positive integers in binary, how can we extend this idea to negative integers?

We could just use the leading bit to denote the sign, i.e. 0b01 = +1 and 0b11 = -1.
But there are issues - this means -0 and +0 have different representations (e.g. 0b10 == -0 and 0b00 == 0) and adding numbers requires us to consider the sign bit separately.

### Solution - 2's Complement

Binary representation formula

<span style="background-color: #0F0FFF"> -x = ~x + 1 </span>

To represent negative integers
1. Consider the binary representation of the absolute positive version
2. Invert those bits
3. Add one

### Examples

1. 10 == 0b00001010

2. -10

> flip the bits: 0b11110101 \
> add 1: 0b11110110

3. 0 == 0b00000000

4. -0
> flip the bits: 0b11111111 \
> add 1: 0b00000000

### Notes
positive/zero numbers - leading/first bit is 0 \
negative numbers - leading bit is 1

We no longer have a different representation for -0.
Fundamental arithemtic operations for signed numbers such as addition, subtraction and multiplication work the same as unsigned binary numbers.

Intuitive Explanation as to why addition of twos complement works:
- The fundamental concept behind two's complement is that it is additive inverse (-3+3=0 for example).
- Another way to look at it, -x = 2^N − x, so -x+x = 2^N. With 8 bits here yields 1 0000 0000, if you ignore the overflow, you get 0.

### Q2 - Converting from Two's Complement

2. Assume that the following hexadecimal values are 16-bit twos-complement. Convert each to the corresponding decimal value.

    ii. 0x0444
    > binary - 0b0000010001000100 \
    > leading bit is a 0, hence this is a positive number \
    > decimal: 1092

    iv. 0xffff
    > binary - 0b 1111 1111 1111 1111 \
    > leading bit is a 1, hence this is a negative number \
    > this is the binary representation for ~x + 1, undo the operations to find the decimal value for -x

    > minus 1: 0b 1111 1111 1111 1110
    > flip the bits to get the value of |-x|: 
    0b 0000 0000 0000 0001
    > decimal: -1

    v. 0x8000
    > binary - 0b 1000 0000 0000 0000 \
    > leading bit is a 1, hence this is a negative number \
    > this is the binary representation for ~x + 1, undo the operations to find the decimal value for -x

    > minus 1 from 0b 1000 0000 0000 0000: 0b 0111 1111 1111 1111 -> this is the binary representation for ~x

    > flip the bits: 0b 1000 0000 0000 0000 -> this is the binary representation for -x \
    > decimal value of 0b 1000 0000 0000 0000 is 32768

    > decimal value of 0x8000: -32768

### Q3 - Convert to Two's Complement

3. Give a representation for each of the following decimal values in 16-bit twos-complement bit-strings. Show the value in binary, octal and hexadecimal.

   iii. 1000
    > binary - 0b1111101000 \
    > hexadecimal - 0x3e8 \
    > octal - 01750

   vi. -5
    > binary - 0b 1111 1111 1111 1011 \
    > binary representation of 5 is 0b 0000 0000 0000 0101 \
    > flip the bits: 0b 1111 1111 1111 1010 \
    > add 1: 0b 1111 1111 1111 1011

    > hexadecimcal - 0xFFFB

    > octal - 0177773

  vii. -100
    > binary representatino of 100 is 0b 0000 0000 0110 0100
    > flip the bits: 0b 1111 1111 1001 1011
    > add 1: 0b 1111 1111 1001 1100
    > binary: 0b 1 111 111 110 011 100

    > hexadecimal: 0xFF9C

    > octal: 0o177634

### Type Casting

Explore in code: \
int16_t i = -1000 \
uint32_t j = i

In C, type casting to an integer type with more bits, the extra space is filled with the leading sign bit.
