# c
C-programming

## Start

### 01_add.c
This first example is showing a couple of things that need attention. And it needs improvement. But let us just compile and run it first. Open your terminal and compile and link it.

```
gcc 01_add.c
```

This will show you warnings. And when you ```ls``` this folder there is a new file ```a.out```. And that is already your executable. You can run it by ```./a.out```. You see a prompt, and then type two numbers like ```32 64``` separated by a space or by a new line. It then responds with the calculated sum ```96```.

When you look into the ```01_add.c``` file using a text editor like Atom, VSCode, etcetera, you can see the line number before every line. And that line number is used to discuss the code.

So line numbers 3 and 5 print information, and line 4 is scanning information (our input). You also see on line 4 and 5 this ```%d``` used for the two numbers that are scanned and the sum that is printed, and this ```d``` is used for ```int``` integer values on line 2. There is also the ```\n``` on line 5 and this is just printing a newline character. Line 4 also has ```&a, &b``` and this is the most difficult! The ```scanf``` scan the input according to its format parameter. And stores the scanned values into the addresses of variables a and b. Remember that ```&a``` is the address of ```a```, or the pointer to ```a```.

When looking on my file system I see that the ```a.out``` is about 8 Kb in size.
It has all kind of binary code, but also the strings that you recognize from the source code.
Use the ```strings``` command;
```
strings a.out
Enter two numbers:
%d%d
Sum: %d
```

When looking at lines of the executable content, I use a hex-dump. This
shows the address, the bytes in hexadecimal and its character (when printable).
```
xxd a.out | head
00000000: cffa edfe 0700 0001 0300 0080 0200 0000  ................
00000010: 0f00 0000 c004 0000 8500 2000 0000 0000  .......... .....
00000020: 1900 0000 4800 0000 5f5f 5041 4745 5a45  ....H...__PAGEZE
00000030: 524f 0000 0000 0000 0000 0000 0000 0000  RO..............
00000040: 0000 0000 0100 0000 0000 0000 0000 0000  ................
00000050: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000060: 0000 0000 0000 0000 1900 0000 d801 0000  ................
00000070: 5f5f 5445 5854 0000 0000 0000 0000 0000  __TEXT..........
00000080: 0000 0000 0100 0000 0010 0000 0000 0000  ................
00000090: 0000 0000 0000 0000 0010 0000 0000 0000  ................

xxd a.out | tail
00002080: 0000 0000 0100 0000 1600 0000 0f01 0000  ................
00002090: 000f 0000 0100 0000 1c00 0000 0100 0001  ................
000020a0: 0000 0000 0000 0000 2400 0000 0100 0001  ........$.......
000020b0: 0000 0000 0000 0000 2b00 0000 0100 0001  ........+.......
000020c0: 0000 0000 0000 0000 0200 0000 0300 0000  ................
000020d0: 0400 0000 0000 0040 0200 0000 0300 0000  .......@........
000020e0: 2000 5f5f 6d68 5f65 7865 6375 7465 5f68   .__mh_execute_h
000020f0: 6561 6465 7200 5f6d 6169 6e00 5f70 7269  eader._main._pri
00002100: 6e74 6600 5f73 6361 6e66 0064 796c 645f  ntf._scanf.dyld_
00002110: 7374 7562 5f62 696e 6465 7200 0000 0000  stub_binder.....
```
The output depends on the operating system and processor.
You don't need to understand it right now!


### 02_add.c

When compiling the previous example, you noticed warnings. The first one started with ```01_add.c:1:1``` and then you can read that something is missing, it is default ```int``` and it shows a ```^``` pointing to the ```m``` of ```main() {``` on the first line. So ```1:1``` indeed means the first line, first character. And we can add that to get a first line of ```int main(){```.

Compiling this gets now one warning less. But what is this? This ```int``` tells that the application returns an integer as exit value, and we will not use that for a while, but lets remember that this is a standard.

So for the other two warnings. These are for lines 3 and 4 and complaining that we are implicitly declaring the printf and scanf. So C doesn't like surprises, we have to explicitly declare these, and then it will not be a surprise anymore when we are using printf and scanf. These two are declared for us in another file, a header file, provided with the compiler. The header name for these standard IO methods is ```stdio.h```. And we then include that, before anything else.
```
#include <stdio.h>
```
Now there is the ```#``` at the start of the line. This indicates a pre-processor step. Where the compiler will, before processing (compiling), replaces the pre-processor lines with their real values. And only then compiles the C code.

There are also ```< >``` around the ```stdio.h``` standard io header file. And that indicates that it is part of the set of header files that are given by the compiler. Later we see that we can also include our own header files, and these are then surrounded by normal double quotes.

Compiling the changed code now doesn't give warnings anymore.

One thing left to do. We need to start ```./a.out``` and there is option to the gcc compiler to directly create the proper output name.
```
gcc 02_add.c -o add
```
Then we can execute the application using ```./add``` like before.

Note, do not type anything else than whole numbers as input, because unexpected things can happen.

### Theory
Inspired by the book 'de programmeertaal C', from ir. L. Ammeraal, Academic Service, 4th edition 1987.

#### Identifiers

A variable name or identifier is a series of characters and digits. It can contain lowercase and uppercase and even an underscore. Examples are;
```
a
my_name
myName
name1
```

#### Keywords

The C language has some keywords that cannot be used as Identifier name.
```
auto, break, case, char, continue, default, do, double, else,
entry, extern, float, for, goto, if, int, long, register,
return, short, sizeof, static, struct, switch, typedef, union,
unsigned, while
```

#### Integer constants
In the first program we typed our numbers, but when these numbers are always the same, these are constant. Here are examples of integer constants.
```
144
0777
0XFFFF
42L
```
These are in Decimal, Octal, Hexadecimal and Long Decimal format.

Octal starts with a zero then digits 0..7.

Hexadecimal starts with 0X or 0x and then digits 0..9 and A..F or a..f.

When a number ends with L, this is a Long and it reserves more memory space to contain larger values.

#### Character constants

Remember in 01_add.c we used ```\n```. This is a character constant for a newline.
The ```\``` backslash is called 'escape character'.
Technically ```\n``` has different output on Linux and Windows, since they use different
characters for a newline.
You might have seen the ASCII table.
The CR and LF are values 13 and 10, or 0x0D and 0x0A.

```
'\n'      new line
'\r'      CR carriage return 0x0D
'\t'      HT horizontal tab 0x09
'\b'      BS backspace 0x08
'\f'      FF form feed
'\\'      \ backslash
'\''      ' single quote
'\ddd'    octal bit pattern, like '\0' for null character 0x00
```

#### Floating point constants

Examples of double precision;
```
3.1415
.01
42.
1e-3
5.2e2
9.e+3
1E2
```

#### String constants

Double quoted strings we also saw in the first example. Used as format string.

Examples;
```
"Enter your name: "
"a"
"Hello, world!\n"
"The answer is %d kilometers.\nAnd that is %d miles.\n"
```
Technically this string takes up some memory space, containing every single character. And automatically every string ends with a null character ```\0```. So there is no need to explicitly end a string with a null character ourselves.

For longer strings that you want to visually break up in your source code, use the escape character followed by a newline. When using that string, that escape character and newline
are then not used.

```
"Some long text that you want to be wrapped in your source code so\
that it is better readable and you do not need to scroll all the\
way to the right to read its content."
```

#### Comment
Comments in source code are ignored by the compiler. A multiline comment starts and ends with this;
```
/* this is a comment */

/* this is also
   a comment
*/

/* and again
 * a comment
 * with some
 * nice formatting
 */

int a, /* comment */ b;
```
And can be anywhere in the source code, since it has a beginning and an end. So it can even be in the middle of a line of code.

Single line comments are always at the end of a the line of code, it ends with the line;
```
// comment until the end of the line

// another comment
// and more

int a, b; // declare a and b
```

#### Expressions
Some calculations;
```
y = x + 1;
y = (x + 1) * 2;
y = (x - 1) * x;
y = a / b;
y = 17 / 3;    // 17/3 = 5 if y is an int
y = 17. / 3;   // 17./3 = 5.666666...
y = 17 % 3;    // 17 modulo 3 = 2 (the remainder)
```
Declaring and assigning these;
```
int main() {
  int a,b;
  float miles;
  char ch;
  a = 1;
  b = a * 2;
  miles = 234.334;
  ch = 'A';
  miles = b;  // convert int to float
  a = ch;     // a gets ASCII character value 65
}
```
Relational and logical operators;
```
<     less than
>     greater than
<=    less or equal than
>=    greater or equal than
==    equals
!=    not equals
&&    logical and
||    logical or
!     not
```

In a logical expression in C, true is ```1``` and false is ```0```.

In a logical expression the system stops evaluating when it already knows the result.
So ```  0 && ( 5 > 3 ) ``` it doesn't even evaluates ``` 5 > 3 ``` since it knows that
at ``` 0 && ... ``` the result will be false.
A similar logical shortcut is for ``` 1 || (5 <= 3) ```, that knows after ``` 1 || ...```
the result will be true and will not evaluate ``` 5 <= 3 ```.
Using logical shortcut is useful, have a quick expressions on the left, and expressions that take a while to calculate on the right.

Precendence of operators;
```
!
*  /   %
+  -
<  <=  >  >=
== !=
&&
||
```

#### Conditional statements
Now that we know expressions, we can use them to drive our program.
```
// if ( expression ) statement1 else statement2

if (a > 0) a = a - 1;

if (1) a = 1;

if (a == b) c = 3 else c = 13;

// indentation is not required but makes it readable
if (a == b)
  c = 3
else
  c = 13;

// combine multiple statements into one compound-statement using { }
if (b > 0) {
  a = b;
  c = b * 2;
} else {
  a = - b * 2
  c = - b;
}

```

Loops...

```
// while ( expression ) statement

i = 0;
while ( i < 100 ) {
  i = i + 1;
}

// for (expression; expression; expression) statement

for (i = 0; i < 100; i = i + 1) x = i;

// you see that even for single statements its better to use { }

for (i = 0; i < 100; i++) {
  x = i;
}

// do statement while (expression);

do {
  i++;
  // something here
} while (i < 100);

```

#### Switch, break and continue
