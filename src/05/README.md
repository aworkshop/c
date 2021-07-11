# Theory (part 2)

## Contents

This theory section contains:
- Operators
- Bitwise Operators
- Ternary operator
- Comma operator
- Casting

Advanced
- Positive values (bit representation)
- Negative values (bit representation)


## Operators

Some is already shown.
```
a = a + b;
i = i + 1;
```
The above can be rewritten as;
```
a += b;
i++;
```
The unary operators;  `++` increment and decrement  `--`.
Unary means that it operates on 1 variable.

Binary operators, like `+`, work on 2 variables.


These following operators can be used together with an assignment operator.
And have the lowest priority.
```
Oper   Expr   Expr      
+=     a+=b   a=a+b
-=     a-=b   a=a-b
*=     a*=b   a=a*b
/=     a/=b   a=a/b
%=     a%=b   a=a%b

<<=    a<<=b  a=a<<b
>>=    a>>=b  a=a>>b
&=     a&=b   a=a&b
^=     a^=b   a=a^b
|=     a|=b   a=a|b
```

## Bitwise Operators

```
&    bitwise and
|    bitwise or
^    bitwise exclusive-or
<<   bitwise shift left
>>   bitwise shift right
~    1-complement (unary)
```

For this it is useful to know about bits and bytes.

See the 06/bits.c


## Ternary operator
We learned about unary and binary operators, and there is a ternary too.
It looks like a quick if-then-else expression using
* `expression ? expression_true : expression_false`

Examples;
```
a = -1;

str = a >= 0 ? "Positive" : "Negative";

x = a < b ? a+1 : b-1;
```

## Comma operator
Comma separator between expressions;
 ` expression1, expression2  `
are evaluated left to right, and the last one determines also the result. Function calls and assignments are also expressions.

```
s=0;
while (scanf("%d", &n), n>0) s+=n;
```

The two expressions in  `while() ` are evaluated left to right, so first a number can be entered, then it is tested if it is a positive number, and while it is, it is added to  `s `.


## Type casting
Type casting is to look at a value with a different type.
```
int i = 42;
long l = (long) i; // cast int to long
//       ^^^^^^ cast
```


# Advanced

## Positive values (bit representation)

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

To specify it use `unsigned`, with `char`, `int`, `short`, and `long`.
```
unsigned char u;   //    0...255
signed   char s;   // -128...127
```


_But how to represent negative values?_


## Negative values (bit representation)

### Two's complement

Suppose we want -128..127 to be stored in our 8 bits. The left most bit then
represents -128 when set, and the other bits are just represent the regular
64..1 positive values. This is called two's complement.

Two's complement | Int
---              | ---
`1000 0000` | -128
`1000 0001` | -127
`1000 0010` | -126
...       | ...
`1111 1111` |  -1
`0000 0000` |  0
`0000 0001` |  1
`0111 1111` |  127


### One's complement

Other implementation is `-127..127`. It just inverts the bits of the positive
representation. Note that it has a both -0 and 0. This is called one's complement.


One's complement | Int
---              | ---
`1000 0000` | -127
`1000 0001` | -126
...       | ...
`1111 1101` | -2
`1111 1110` | -1
`1111 1111` | -0
`0000 0000` | 0
`0000 0001` | 1
`0000 0010` | 2
...       | ...
`0111 1110` | 126
`0111 1111` | 127

These are two implementations; One's complement, and Two's complement.
(https://en.wikipedia.org/wiki/Ones%27_complement)
(https://en.wikipedia.org/wiki/Two%27s_complement)


---
|[TOC](../../README.md) | [Prev](../04/README.md) |[Next](../06/README.md)|