# Chapter 2 Practice Problems

## P-P 2.1
Perform the following number conversions:
- A. `0x25B9D2` to binary
- B. binary `1010111001001001` to hexadecimal
- C. `0xA8B3D` to binary
- D. binary `1100100010110110010110` to hexadecimal

Solution:
- A. 0x25B9D2₁₆ = 0010-0101-1011-1001-1101-0010 = 1001011011100111010010₂
- B. 1010111001001001₂ = 1010-1110-0100-1001 = 0xAE49₁₆
- C. 0xA8B3D₁₆ = 1010-1000-1011-0011-1101 = 10101000101100111101₂
- D. 1100100010110110010110₂ = 0011-0010-0010-1101-1001-0110 = 0x322D96₁₆

## P-P 2.2
Fill in the blank entries in the following table, giving the decimal and hexadecimal representations of different powers of 2:
- n = 5, 2^n = 32, 0x20
- n = 23, 2^n = ?, ?
- n = ?, 2^n = 32768, ?
- n = ?, 2^n = ?, 0x2000
- n = 12, 2^n = ?, ?
- n = ?, 2^n = 64, ?
- n = ?, 2^n = ?, 0x100

Solution:
- n = 5, 2^n = 32, 0x20
- n = 23, 2^n = 8388608, 0x800000
- n = 15, 2^n = 32768, 0x8000
- n = 13, 2^n = 8192, 0x2000
- n = 12, 2^n = 4096, 0x1000
- n = 6, 2^n = 64, 0x40
- n = 8, 2^n = 256, 0x100

## P-P 2.3
A single byte can be represented by 2 hexadecimal digits. Fill in the missing entries in the following table, giving the decimal, binary, 
and hexadecimal values of different byte patterns:
- Decimal     Binary           Hexadecimal
- 0           0000 0000        0x00
- 158         ?                ?
- 76          ?                ?
- 145         ?                ?
- ?           1010 1110        ?
- ?           0011 1100        ?
- ?           1111 0001        ?
- ?           ?                0x75
- ?           ?                0xBD
- ?           ?                0xF5

Solution:
1. - Decimal to binary: 158 = 79 × 2 + 0 (0), 79 = 39 × 2 + 1 (1), 39 = 19 × 2 + 1 (1), 19 = 9 × 2 + 1 (1), 9 = 4 × 2 + 1 (1), 4 = 2 × 2 + 0 (0), 2 = 2 × 1 + 0 (0); 158₁₀ = 10011110₂.
   - Binary to hexadecimal: 10011110₂ = 1001-1110 = 0x9E₁₆.
2. - Decimal to binary: 76 = 38 × 2 + 0 (0), 38 = 19 × 2 + 0 (0), 19 = 9 × 2 + 1 (1), 9 = 4 × 2 + 1 (1), 4 = 2 × 2 + 0 (0), 2 = 2 × 1 + 0 (0);  76₁₀ = 1001100₂.
   - Binary to hexadecimal: 1001100₂ = 0100-1100 = 0x4C₁₆.
3. - Decimal to binary: 145 = 72 × 2 + 1 (1), 72 = 36 × 2 + 0 (0), 36 = 18 × 2 + 0 (0), 18 = 9 × 2 + 0 (0), 9 = 4 × 2 + 1 (1), 4 = 2 × 2 + 0 (0), 2 = 2 × 1 + 0 (0); 145₁₀ = 10010001₂.
   - Binary to hexadecimal: 10010001₂ = 1001-0001 = 0x91₁₆.
4. - Binary to decimal: 10101110₂ = 1 × 2^7 + 0 × 2^6 +  1 × 2^5 + 0 × 2^4 + 1 × 2^3 + 1 × 2^2 + 1 × 2^1 + 0 × 2^0 = 174₁₀.
   - Binary to hexadecimal: 10101110₂ = 1010-1110 = 0xAE₁₆.
5. - Binary to decimal: 00111100₂ = 0 × 2^7 + 0 × 2^6 + 1 × 2^5 + 1 × 2^4 + 1 × 2^3 + 1 × 2^2 + 0 × 2^1 + 0 × 2^0 = 60₁₀.
   - Binary to hexadecimal: 00111100₂ = 0011-1100 = 0x3C₁₆.
6. - Binary to decimal: 11110001₂ = 1 × 2^7 + 1 × 2^6 + 1 × 2^5 + 1 × 2^4 + 0 × 2^3 + 0 × 2^2 + 0 × 2^1 + 1 × 2^0 = 241₁₀.
   - Binary to hexadecimal: 11110001₂ = 1111-0001 = 0xF1₁₆.
7. - Hexadecimal to binary: 0x75₁₆ = 0111-0101 = 01110101₂.
   - Binary to decimal: 01110101₂ = 0 × 2^7 + 1 × 2^6 + 1 × 2^5 + 1 × 2^4 + 0 × 2^3 + 1 × 2^2 + 0 × 2^1 + 1 × 2^0 = 116₁₀.
8. - Hexadecimal to binary: 0xBD₁₆ = 1011-1101 = 10111101₂.
   - Binary to decimal: 10111101₂ = 1 × 2^7 + 0 × 2^6 + 1 × 2^5 + 1 × 2^4 + 1 × 2^3 + 1 × 2^2 + 0 × 2^1 + 1 × 2^0 = 189₁₀.
9. - Hexadecimal to binary: 0xF5₁₆ = 1111-0101 = 11110101₂.
   - Binary to decimal: 11110101₂ = 1 × 2^7 + 1 × 2^6 + 1 × 2^5 + 1 × 2^4 + 0 × 2^3 + 1 × 2^2 + 0 × 2^1 + 1 × 2^0 = 245₁₀.

## P-P 2.4
Without converting the numbers to decimal or binary, try to solve the following arithmetic problems, giving the answers in hexadecimal. Hint: Just modify 
the methods you use for performing decimal addition and subtraction to use base 16.
- A. 0x605c + 0x5 =
- B. 0x605c − 0x20 =
- C. 0x605c + 32 =
- D. 0x60fa − 0x605c =

Solution:
- A. 0x605C + 0x5 = 0x605C + 0x0005 = 0x6061.
- B. 0x605C − 0x20 = 0x605C − 0x0020 = 0x603C.
- C. 0x605C + 32 = 0x605C + 0x0020 = 0x607C.
- D. 0x60FA − 0x605C = 0x9E.

## P-P 2.5
Consider the following three calls to show_bytes:
```c
int a = 0x12345678;
byte_pointer ap = (byte_pointer) &a;
show_bytes(ap, 1); /* A. */
show_bytes(ap, 2); /* B. */
show_bytes(ap, 3); /* C. */
```
Indicate the values that will be printed by each call on a little-endian machine and on a big-endian machine:
- A. Little endian:       Big endian:
- B. Little endian:       Big endian:
- C. Little endian:       Big endian:

Solution:
- A. Little endian: 78          Big endian: 12
- B. Little endian: 78 56       Big endian: 12 34
- C. Little endian: 78 56 34    Big endian: 12 34 56

## P-P 2.6
Using `show_int` and `show_float`, we determine that the integer 2607352 has hexadecimal representation 0x0027C8F8, while the floating-point number 3510593.0 has hexadecimal representation 0x4A1F23E0.
- A. Write the binary representations of these two hexadecimal values.
- B. Shift these two strings relative to one another to maximize the number of
matching bits. How many bits match?
- C. What parts of the strings do not match?

Solution:
- A. 0x0027C8F8₁₆ = 0010-0111-1100-1000-1111-1000 = 1001111100100011111000₂; 0x4A1F23E0₁₆ = 0100-1010-0001-1111-0010-0011-1110-0000 = 1001010000111110010001111100000₂;

## P-P 2.7
What would be printed as a result of the following call to `show_bytes`?
```c
const char *m = "mnopqr";
show_bytes((byte_pointer) m, strlen(m));
```
Note that letters ‘a’ through ‘z’ have ASCII codes 0x61 through 0x7A.

Solution: "mnopqr" => 6D 6E 6F 70 71 72

## P-P 2.8
Fill in the following table showing the results of evaluating Boolean operations on bit vectors. a = [01001110], b = [11100001]

Solution: ~a = 10110001; ~b = 00011110; a & b = 01000000; a | b = 11101111; a ^ b = 10101111;

## P-P 2.9
Solution: 
- A. 
   - 1) Black - [000], complement: ~[000] = [111] -> White; 
   - 2) Blue - [001], ~[001] = [110] -> Yellow;
   - 3) Green - [010], ~[010] = [101] -> Magenta;
   - 4) Cyan - [011], ~[011] = [100] -> Red;
   - 5) Red - [100], ~[100] = [011] -> Cyan;
   - 6) Magenta - [101], ~[101] = [010] -> Green;
   - 7) Yellow - [110], ~[110] = [001] -> Blue;
   - 8) White - [111], ~[111] = [000] -> Black;

- B. 
   - Blue | Green = [001] | [010] = [011] -> Cyan;
   - Yellow & Cyan = [110] & [011] = [010] -> Green;
   - Red ^ Magenta = [100] ^ [101] = [001] -> Blue;

## P-P 2.10
Solution: 
- Step 1: *x = a; *y = a ^ b;
- Step 2: *x = a ^ (a ^ b) = (a ^ a) ^ b = 0 ^ b = b; *y = a ^ b;
- Step 3: *x = b; *y = b ^ (a ^ b) = (b ^ b) ^ a = a;

## P-P 2.11
Solution:
- A. For an array of odd length cnt = 2k + 1, the final first = last = k;
- B. When calling the function inplace_swap with the *x, *y which references the same location, in Step 1 we get 0 for both, and in the next steps the values keep the same.
- C. After changing `first <= last` to `first < last`, we skip swapping the final middle element with itself.

## P-P 2.12
Solution:
- A. 
```c
int x = 0x87654321;
int mask = 0xFF;
printf("result = 0x%X\n", x & mask);
```
- B.
```c
int x = 0x87654321;
int mask = 0xFF;
printf("result = 0x%X\n", x ^ ~mask);
```
- C.
```c
int x = 0x87654321;
int mask = 0xFF;
printf("result = 0x%X\n", x | mask);
```

## P-P 2.13
Solution:
```c
#include <stdio.h>

int bis(int x, int m);
int bic(int x, int m);
int bool_or(int x, int y);
int bool_xor(int x, int y);

int main()
{
    int x = 0b1110, y = 0b1101;
    printf("%d\n", bool_or(x, y) == (x | y));
    printf("%d\n", bool_xor(x, y) == (x ^ y));

    return 0;
}

int bis(int x, int m)
{
    return x | m;
}

int bic(int x, int m)
{
    return x & ~m;
}

int bool_or(int x, int y)
{
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y)
{
    /* x ^ y = (x & ~y) | (~x & y) */
    int result = bis(bic(x, y), bic(y, x));
    return result;
}
```

## P-P 2.14
Suppose that a and b have byte values 0x55 and 0x46, respectively. Fill in the following table indicating the byte values of the different C expressions.

Solution: a = 0x55 = 01010101, b = 0x46 = 01000110; 
- a & b = 01010101 & 01000110 = 01000100 = 0x44;
- a | b = 01010101 | 01000110 = 01010111 = 0x57;
- ~a | ~b = ~01010101 | ~01000110 = 10101010 | 10111001 = 10111011 = 0xBB;
- a & !b = 0x55 & !0x46 = 0x55 & 0x00 = 0x00;
- a && b = 0x55 && 0x46 = 0x01;
- a || b = 0x55 || 0x46 = 0x01;
- !a || !b = !0x55 || !0x46 = 0x00 || 0x00 = 0x00;
- a && ~b = 0x55 && ~0x46 = 0x01;

## P-P 2.15
Using only bit-level and logical operations, write a C expression that is equivalent
to x == y. In other words, it will return 1 when x and y are equal and 0 otherwise.

Solution: x ^ y = 0, for x = y, !(x ^ y) is equivalent to x == y.

## P-P 2.16
Solution:
- a = 0xD4₁₆ = 11010100₂; a << 2 = 01010000₂ = 0x50₁₆; logical: a >> 3 = 00011010₂ = 0x1A₁₆; arithmetic: a >> 3 = 11111010₂ = 0xFA₁₆;
- a = 0x64₁₆ = 01100100₂; a << 2 = 10010000₂ = 0x90₁₆; a >> 3 = 00001100₂ = 0x0C₁₆;
- a = 0x72₁₆ = 01110010₂; a << 2 = 11001000₂ = 0xC8₁₆; a >> 3 = 00001110₂ = 0x0E₁₆;
- a = 0x44₁₆ = 01000100₂; a << 2 = 00010000₂ = 0x10₁₆; a >> 3 = 00001000₂ = 0x08₁₆;

## P-P 2.17
Solution:
- 0x1 = [0001], B2U(4)(x) = 1 × 2^0 = 1, B2T(4)(x) = 1 × 2^0 = 1;
- 0xB = [1011], B2U(4)(x) = 1 × 2^3 + 1 × 2^1 + 1 × 2^0 = 11, B2T(4)(x) = -1 × 2^3 + 1 × 2^1 + 1 × 2^0 = -5;
- 0x2 = [0010], B2U(4)(x) = 1 × 2^1 = 2, B2T(4)(x) = 1 × 2^1 = 2;
- 0x7 = [0111], B2U(4)(x) = 1 × 2^2 + 1 × 2^1 + 1 × 2^0 = 7, B2T(4)(x) = 1 × 2^2 + 1 × 2^1 + 1 × 2^0 = 7;
- 0xC = [1100], B2U(4)(x) = 1 × 2^3 + 1 × 2^2 = 12, B2T(4)(x) = -1 × 2^3 + 1 × 2^2 = -4;

## P-P 2.19
Solution:
- x = -1, T2B(4)(x) = [1111], B2U(4)([1111]) = 15;
- x = -5, T2B(4)(x) = [1011], B2U(4)([1011]) = 11;
- x = -6, T2B(4)(x) = [1010], B2U(4)([1010]) = 10;
- x = -4, T2B(4)(x) = [1100], B2U(4)([1100]) = 12;
- x = 1, T2B(4)(x) = [0001], B2U(4)([0001]) = 1;
- x = 8, T2U(4)(x) = 8;