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
1. - Decimal to binary: 158 = 79 × 2 + 0 (0), 79 = 39 × 2 + 1 (1), 39 = 19 × 2 + 1 (1), 19 = 9 × 2 + 1 (1), 9 = 4 × 2 + 1 (1), 2 = 2 × 1 + 0 (0); 158₁₀ = 011110₂.
   - Binary to hexadecimal: 011110₂ = 0001-1110 = 0x1E₁₆.
2. - Decimal to binary: 76 = 38 × 2 + 0 (0), 38 = 19 × 2 + 0 (0), 19 = 9 × 2 + 1 (1), 9 = 4 × 2 + 1 (1), 4 = 2 × 2 + 0 (0); 76₁₀ = 01100₂.
   - Binary to hexadecimal: 01100₂ = 1100 = 0xC₁₆.
3. - Decimal to binary: 145 = 72 × 2 + 1 (1), 72 = 36 × 2 + 0 (0), 36 = 18 × 2 + 0 (0), 18 = 9 × 2 + 0 (0), 9 = 4 × 2 + 1 (1), 4 = 2 × 2 + 0 (0); 145₁₀ = 010001₂.
   - Binary to hexadecimal: 010001₂ = 0001-0001 = 0x11₁₆.
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