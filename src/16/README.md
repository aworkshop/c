## 16/ascii.c

This just produces an ASCII character table.

Output;

```
$ ./ascii
Dec Hex Char | Dec Hex Char | Dec Hex Char | Dec Hex Char | 
  0  00  NUL |  32  20      |  64  40  @   |  96  60  `   | 
  1  01  SOH |  33  21  !   |  65  41  A   |  97  61  a   | 
  2  02  STX |  34  22  "   |  66  42  B   |  98  62  b   | 
  3  03  ETX |  35  23  #   |  67  43  C   |  99  63  c   | 
  4  04  EOT |  36  24  $   |  68  44  D   | 100  64  d   | 
  5  05  ENQ |  37  25  %   |  69  45  E   | 101  65  e   | 
  6  06  ACK |  38  26  &   |  70  46  F   | 102  66  f   | 
  7  07  BEL |  39  27  '   |  71  47  G   | 103  67  g   | 
  8  08  BS  |  40  28  (   |  72  48  H   | 104  68  h   | 
  9  09  TAB |  41  29  )   |  73  49  I   | 105  69  i   | 
 10  0A  LF  |  42  2A  *   |  74  4A  J   | 106  6A  j   | 
 11  0B  VT  |  43  2B  +   |  75  4B  K   | 107  6B  k   | 
 12  0C  FF  |  44  2C  ,   |  76  4C  L   | 108  6C  l   | 
 13  0D  CR  |  45  2D  -   |  77  4D  M   | 109  6D  m   | 
 14  0E  SO  |  46  2E  .   |  78  4E  N   | 110  6E  n   | 
 15  0F  SI  |  47  2F  /   |  79  4F  O   | 111  6F  o   | 
 16  10  DLE |  48  30  0   |  80  50  P   | 112  70  p   | 
 17  11  DC1 |  49  31  1   |  81  51  Q   | 113  71  q   | 
 18  12  DC2 |  50  32  2   |  82  52  R   | 114  72  r   | 
 19  13  DC3 |  51  33  3   |  83  53  S   | 115  73  s   | 
 20  14  DC4 |  52  34  4   |  84  54  T   | 116  74  t   | 
 21  15  NAK |  53  35  5   |  85  55  U   | 117  75  u   | 
 22  16  SYN |  54  36  6   |  86  56  V   | 118  76  v   | 
 23  17  ETB |  55  37  7   |  87  57  W   | 119  77  w   | 
 24  18  CAN |  56  38  8   |  88  58  X   | 120  78  x   | 
 25  19  EM  |  57  39  9   |  89  59  Y   | 121  79  y   | 
 26  1A  SUB |  58  3A  :   |  90  5A  Z   | 122  7A  z   | 
 27  1B  ESC |  59  3B  ;   |  91  5B  [   | 123  7B  {   | 
 28  1C  FS  |  60  3C  <   |  92  5C  \   | 124  7C  |   | 
 29  1D  GS  |  61  3D  =   |  93  5D  ]   | 125  7D  }   | 
 30  1E  RS  |  62  3E  >   |  94  5E  ^   | 126  7E  ~   | 
 31  1F  US  |  63  3F  ?   |  95  5F  _   | 127  7F     | 
 ```

Since character 127 is a `DEL` delete character, some systems display
it different. Also the first 32 characters are not printable.
This could be tested in code, using `isprint()`.

The most interesting in this code is maybe the format string.


## 16/atbash.c

Custom written tool for solving a challenge. Atbash replaces the Nth char in A-Z with the (27-N) char. So A becomes Z and Z becomes A.
```
$ echo "This is supersecret information." |./atbash
Gsrh rh hfkvihvxivg rmulinzgrlm.
```

## 16/base64decode.c

Base64 tools are probably already available on your machine. It can be openssl or base64 or cyberchef, or a replace... I used this to solve a challenge, to be able to tweak the charsets. It uses the characterset for standard base64 _and_ for URL. So `+` and `-` are the same. And `/` and `_` are the same. By doing this, it is customizable for challenges, like ignoring linefeeds.

In the code we need to do some bit shifting.

```
$ echo "cGFzc3dvcmQK" |./base64decode 
password
```

## 16/count.c

This `count` tool counts the occurence of characters/bytes. It uses standard input. 
And it suppresses lines that have counts of zero.
For some challenges this can give ideas to investigate next.

```
$ echo -n "hackthebox" | ./count
0x60 ` 0        0x61 a 1        0x62 b 1        0x63 c 1        0x64 d 0        0x65 e 1        0x66 f 0        0x67 g 0
0x68 h 2        0x69 i 0        0x6a j 0        0x6b k 1        0x6c l 0        0x6d m 0        0x6e n 0        0x6f o 1
0x70 p 0        0x71 q 0        0x72 r 0        0x73 s 0        0x74 t 1        0x75 u 0        0x76 v 0        0x77 w 0
0x78 x 1        0x79 y 0        0x7a z 0        0x7b { 0        0x7c | 0        0x7d } 0        0x7e ~ 0        0x7f . 0
```

Another example (output is copied from other machine, so formatting is different here)
```
$ python3 -c "print('Hello_World',end='')" | ./count
0x48 H 1	0x49 I 0	0x4a J 0	0x4b K 0	0x4c L 0	0x4d M 0	0x4e N 0	0x4f O 0	
0x50 P 0	0x51 Q 0	0x52 R 0	0x53 S 0	0x54 T 0	0x55 U 0	0x56 V 0	0x57 W 1	
0x58 X 0	0x59 Y 0	0x5a Z 0	0x5b [ 0	0x5c \ 0	0x5d ] 0	0x5e ^ 0	0x5f _ 1	
0x60 ` 0	0x61 a 0	0x62 b 0	0x63 c 0	0x64 d 1	0x65 e 1	0x66 f 0	0x67 g 0	
0x68 h 0	0x69 i 0	0x6a j 0	0x6b k 0	0x6c l 3	0x6d m 0	0x6e n 0	0x6f o 2	
0x70 p 0	0x71 q 0	0x72 r 1	0x73 s 0	0x74 t 0	0x75 u 0	0x76 v 0	0x77 w 0	
```

## 16/patch.c

This **CHANGES** bytes in a file. The first arg is the file, then the address and then a series of bytes.

Let us test this tool on a fake challenge `testme.c`. Suppose there is a binary that is compiled from a source like this. So you need to supply `secret` and then it reveals the flag. 

```
#include <stdio.h>
#include <string.h>
int main(int argc, char*argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1],"secret") == 0) {
            printf("flag{hi}");
        }
    }
    return 0;
}
```
So compile it and look at the main method in the binary.
```
$ gcc testme.c -o testme
$ objdump -df=_main -S testme

testme: file format Mach-O 64-bit x86-64

Disassembly of section __TEXT,__text:
_main:
100000f10:      55      pushq   %rbp
100000f11:      48 89 e5        movq    %rsp, %rbp
100000f14:      48 83 ec 20     subq    $32, %rsp
100000f18:      c7 45 fc 00 00 00 00    movl    $0, -4(%rbp)
100000f1f:      89 7d f8        movl    %edi, -8(%rbp)
100000f22:      48 89 75 f0     movq    %rsi, -16(%rbp)
100000f26:      83 7d f8 02     cmpl    $2, -8(%rbp)
100000f2a:      0f 85 33 00 00 00       jne     51 <_main+0x53>
100000f30:      48 8b 45 f0     movq    -16(%rbp), %rax
100000f34:      48 8b 78 08     movq    8(%rax), %rdi
100000f38:      48 8d 35 5d 00 00 00    leaq    93(%rip), %rsi
100000f3f:      e8 2e 00 00 00  callq   46 <dyld_stub_binder+0x100000f72>
100000f44:      83 f8 00        cmpl    $0, %eax
100000f47:      0f 85 11 00 00 00       jne     17 <_main+0x4e>
100000f4d:      48 8d 3d 4f 00 00 00    leaq    79(%rip), %rdi
100000f54:      b0 00   movb    $0, %al
100000f56:      e8 11 00 00 00  callq   17 <dyld_stub_binder+0x100000f6c>
100000f5b:      89 45 ec        movl    %eax, -20(%rbp)
100000f5e:      e9 00 00 00 00  jmp     0 <_main+0x53>
100000f63:      31 c0   xorl    %eax, %eax
100000f65:      48 83 c4 20     addq    $32, %rsp
100000f69:      5d      popq    %rbp
100000f6a:      c3      retq
```
We know there is some compare in the app, so try to change it! This can definitely corrupt the executable.
Search for the JNE (jump if not equal `0F 85`) and see there are similar ones, like JE, and there is one `0F 84`.

https://faydoc.tripod.com/cpu/jne.htm
https://faydoc.tripod.com/cpu/je.htm

So where is that code, let us look for these bytes, and we find 3 lines that have both `0f` and `85`.
And the second and third line have these bytes next to each other. But we also see these are the
two `jne`. The second line has `33` and the third line has the `11` next to it.
Lets now change this address `0xf48` from `85` to `84`.
```
$ xxd testme |grep 0f|grep 85
00000010: 0f00 0000 c004 0000 8500 2000 0000 0000  .......... .....
00000f20: 7df8 4889 75f0 837d f802 0f85 3300 0000  }.H.u..}....3...
00000f40: 2e00 0000 83f8 000f 8511 0000 0048 8d3d  .............H.=
```
So we change the file and try if this had an effect.
```
$ ./patch testme 0xf48 84
$ ./testme guess
flag{hi}
```

## 16/phone.c

This is used in a challenge.

Old phone decoding. 
https://en.wikipedia.org/wiki/Telephone_keypad

When pressing a digit multiple times, then the characters are formed. 
Pressing 2 gets A, 22 gets B, 222 gets C. 
Then 3 gets D etcetera. 
Not all chars are in the set. 
Sets with 7 or 9 are 4 long.
0 and 1 are not used.

```
$ echo "44822" |./phone
HTB
```

## 16/testme.c

This is part of `patch.c`.
