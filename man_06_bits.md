
## 06_bits.c

Unfortunately there is no format string that prints binary output,
but octal and hexadecimal can show us what the operators do.

```
#include <stdio.h>

int main() {
  int i = 0x0F;
  int j = 0x08;
  int k = 0x10;
  int l = 0x11;
  int s = 2;

  printf("The result of %02X & %02X is %02X.\n", i, j, i&j);
  printf("The result of %02X | %02X is %02X.\n", i, k, i|k);
  printf("The result of %02X ^ %02X is %02X.\n", i, l, i^l);
  printf("The result of %02X << %02X is %02X.\n", k, s, k<<s);
  printf("The result of %02X >> %02X is %02X.\n", k, s, k>>s);
  printf("The result of ~%02X is %0X.\n", l, ~l);

}
```

The output of running this code is (values are hexadecimal);
```
The result of 0F | 10 is 1F.
The result of 0F ^ 11 is 1E.
The result of 10 << 02 is 40.
The result of 10 >> 02 is 04.
The result of ~11 is FFFFFFEE.
```

In this example we also saw a format string `%02X` this is hexadecimal in
capitals and 2 wide with leading zeroes.

We see that int is 4 bytes (the hexadecimal is 8 characters) on this system.
The `limits.h` has limits defined.


## Positive values
A byte has 8 bits, two nibbles, `0000 0000`. The most left bit represents the
highest value (128), and most right bit the lowest value (1). When all bits are
set `1111 1111` this is 255 (=128+64+32+16+8+4+2+1). Which is nice when working
with positive values 0..255 only.

Positive  | Int
---       | ---
0000 0000 | 0
0000 0001 | 1
0000 0010 | 2
...       | ...
1111 1110 | 254
1111 1111 | 255

_But how to represent negative values?_


## Negative values

Suppose we want -128..127 to be stored in our 8 bits. The left most bit then
represents -128 when set, and the other bits are just represent the regular
64..1 positive values. This is called two's complement.

Two's complement | Int
---              | ---
1000 0000 | -128
1000 0001 | -127
1000 0010 | -126
...       | ...
1111 1111 |  -1
0000 0000 |  0
0000 0001 |  1
0111 1111 |  127

Other implementation is -127..127. It just inverts the bits of the positive
representation. Note that it has a -0 and 0. This is called one's complement.

One's complement | Int
---              | ---
1000 0000 | -127
1000 0001 | -126
...       | ...
1111 1101 | -2
1111 1110 | -1
1111 1111 | -0
0000 0000 | 0
0000 0001 | 1
0000 0010 | 2
...       | ...
0111 1110 | 126
0111 1111 | 127

There are two implementations; One's complement, and Two's complement.
(https://en.wikipedia.org/wiki/Ones%27_complement)
(https://en.wikipedia.org/wiki/Two%27s_complement)
