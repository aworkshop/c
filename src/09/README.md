## 09/hexdump.c

This example code is showing code with some new topics. Try to optimize it!

```
echo "Hello HackDeWereld and HackTheBox."|./a.out
00000000: 48 65 6c 6c 6f 20 48 61 63 6b 44 65 57 65 72 65 |Hello HackDeWere|
00000010: 6c 64 20 61 6e 64 20 48 61 63 6b 54 68 65 42 6f |ld and HackTheBo|
00000020: 78 2e 0a                                        |x..             |
```

Using `#define` is useful to define a single place that can be reused
in the code. These are NOT constants. The pre-compile will replace all
occurrences in the code with its value. So this has implications. When there
is a larger expression, and it is used often, consider making a function
instead. Also when using parameters, expressions can go wrong. Example;
```
#define ABS(v) v+1>0?v:-v;
int i = ABS(-1);
int j = ABS(a*2+b); // expanded to: a*2+b+1>0?a*2+b:-a*2+b;
                    //                              ^^^^^^
```

The fread() is reading from a FILE, in this case `stdin`. It is reading
into the `inp` with `LEN` * `sizeof(char)` size. Then `n`
contains the number that was really read. The `sizeof()` returns the
size in bytes of a type. For `int` or `long` it requires more.


## 09/arrays.c

Look in the code itself. 

It shows more more includes, functions, while- and for-loops. Some new functions
like `strlen()`, `putchar()` and `toupper()`.

But the focus here is arrays.
**A char array must always end with '\0'.** And it has a demo that goes wrong.

And then there is some pointer calculations with side-effects.


## 09/strings.c

Look in the code itself. 

It shows more from the `string.h`; `strcmp()`, `strcpy()`, `strcat()`, `strlen()`, `strtok()`.

And a variation `fprintf()` that can print to `FILE*`, in this case to `stderr` and `stdout`.

## 09/memory.c

Look in the code itself.

It shows `malloc()`, `calloc()` and `free()`, when you want to allocate and free memory blocks to store 
strings, arrays, structures, etcetera.


---
|[TOC](../../README.md) | [Prev](../08/README.md) |[Next](../10/README.md)|