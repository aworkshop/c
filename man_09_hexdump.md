## 09_hexdump.c

This example code is showing code with some new topics. Try to optimize it!

```
echo "Hello HackDeWereld and HackTheBox."|./a.out
00000000: 48 65 6c 6c 6f 20 48 61 63 6b 44 65 57 65 72 65 |Hello HackDeWere|
00000010: 6c 64 20 61 6e 64 20 48 61 63 6b 54 68 65 42 6f |ld and HackTheBo|
00000020: 78 2e 0a                                        |x..             |
```

Using ```#define``` is useful to define a single place that can be reused
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

The fread() is reading from a FILE, in this case ```stdin```. It is reading
into the ```inp``` with ```LEN``` * ```sizeof(char)``` size. Then ```n```
contains the number that was really read. The ```sizeof()``` returns the
size in bytes of a type. For ```int``` or ```long``` it requires more.
