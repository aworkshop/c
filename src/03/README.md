# Theory (part 1)

Inspired by the book 'de programmeertaal C', from ir. L. Ammeraal, Academic Service, 4th edition 1987.
But it is not a copy.

## Contents

This theory section contains:
- Identifiers
- Keywords
- Integer constants
- Character constants
- Floating point constants
- String constants
- Comment
- Expressions
- Relational and logical operators
- Conditional statements
- Loops: while, for, and do-while
- Switch, break and continue


## Identifiers

A variable name or identifier is a series of characters and digits. It can contain lowercase and uppercase and even an underscore. It cannot start with a digit. Examples are;
```
a
my_name
myName
name1
```

## Keywords

The C language has some keywords that cannot be used as Identifier name.
```
auto, break, case, char, continue, default, do, double, else,
entry, extern, float, for, goto, if, int, long, register,
return, short, sizeof, static, struct, switch, typedef, union,
unsigned, while
```


## Integer constants
In the first program we typed our numbers, but when these numbers are always the same, these are constant. Here are examples of integer constants.
```
144             positive int
-10             negative int
0777            octal int
0XFFFF          hexadecimal int
0xCAFEBABE      hexadecimal int
42L             long int
```
These are in Decimal, Octal, Hexadecimal and Long Decimal format.

* Octal starts with a zero then digits 0..7.
* Hexadecimal starts with 0X or 0x and then digits 0..9 and A..F or a..f.
* When a number ends with L, this is a Long and it reserves more memory space to contain larger values.


## Character constants

Remember in 02/add2.c we used `\n`. This is a character constant for a newline.
The `\` backslash is called 'escape character'.

Technically `\n` has different output on Linux and Windows, since they use different
characters for a newline.
You might have seen the ASCII table.
The `CR` and `LF` are values `13` and `10`, or `0x0D` and `0x0A`.

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

## Floating point constants

Examples of  floating point constants;
```
3.1415
.01
42.
1e-3
5.2e2
9.e+3
1E2
```

## String constants

Double quoted strings we also saw in the first example. Used as format string.

Examples;
```
"Enter your name: "
"a"
"Hello, world!\n"
"The answer is %d kilometers.\nAnd that is %d miles.\n"
```
Technically this string takes up some memory space, containing every single character. And automatically every string ends with a null character  `\0 `. So there is no need to explicitly end a string with a null character ourselves.

For longer strings that you want to visually break up in your source code, use the escape character followed by a newline. When using that string, that escape character and newline
are then not used.

```
"Some long text that you want to be wrapped in your source code so\
that it is better readable and you do not need to scroll all the\
way to the right to read its content."
```

## Comment
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

Single line comments are always at the end of a the line of code, it ends with the newline;
```
// comment until the end of the line

// another comment
// and more

int a, b; // declare a and b
```

## Expressions
Some calculations;
```
y = x + 1;
y = (x + 1) * 2;
y = (x - 1) * x;
y = a / b;
y = 17 / 3;    // 17/3 = 5 if y is an int
y = 17. / 3;   // 17./3 = 5.666666...
y = 17 % 3;    // 17 modulo 3 = 2 (the remainder)
y = abs( b );  // function call
y = a > 0;     // comparison results in 0 or 1
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

## Relational and logical operators

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

In a logical expression in C, 
* true is `1` (technically anything other than 0) and 
* false is `0`.

A bug is to use `=` instead of `==`. 
What happens here: `if ((pin=8179)) give_money();`.

### Logical shortcut

In a logical expression the system stops evaluating when it already knows the result.

- So expression `0 && ( 5 > 3 )` it doesn't even evaluates `5 > 3` since it knows that at `0 && ...` the result will be false.
- A similar logical shortcut is for `1 || (5 <= 3)`, that knows after `1 || ...` the result will be true and will not evaluate `5 <= 3`.

Using logical shortcut is useful, have a quick expressions on the left, and expressions that take a while to calculate on the right.

 **It can mean that a function is not executed**.


### Precendence of operators
Operator list in descending order of execution;
```
!
*  /   %
+  -
<  <=  >  >=
== !=
&&
||
```

## Conditional statements if-then-else
Now that we know expressions, we can use them to drive our program.
```
// if ( expression ) statement1 else statement2

if (a > 0) a = a - 1;

if (1) a = 1;

if (a == b) c = 3; else c = 13;

// indentation is not required but makes it readable
if (a == b)
  c = 3;
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

## Loops: while, for, and do-while
Loops repeat the same code until a condition is invalid.

The `while` has its condition at the beginning of the loop, and it will be
evaluated again after the end of the statement. Make sure that this loop
is not infinite. Alter variables in the loop that are used in the expression.
Or `break` out of the loop.
```
// while ( expression ) statement
i = 0;
while ( i < 100 ) {
  x = i;
  i = i + 1;
}
```

A `for` looks a bit like this previous while. But combines the 3 expressions.
The first expression is executed once. Then the second expression is evaluated,
and when true then the statement is executed. At the end of the statement the
third expression is executed. Then the second iteration starts by evaluating
the second expression again.
```
// for (expression; expression; expression) statement
int i;
for (i = 0; i < 100; i = i + 1) x = i;

// you see that even for single statements its better to use { }
for (i = 0; i < 100; i++) {
  x = i;
}
```


And the do-while has the condition at the end. Note the `;` after the
expression. Make sure it is not an infinite loop.
```
// do statement while (expression);
do {
  x = i;
  i++;
} while (i < 100);

```

## Switch, break and continue
When you want to work with multiple options, the switch-case can be used.
```
// the expression is of type int or char
switch (ch) {
  case 'A': printf("Aardvark\n"); break;
  case 'B': printf("Bear\n"); break;
  case 'C': printf("Cat\n"); break;
  case 'Z': printf("Zebra\n"); break;
  default : printf("Some animal\n"); break;
}
```
After each `:` multiple statements can be executed until `break`. That stops
the `case` and leaves the `switch` statement.

In the following example, the `break` is missing. This can be on-purpose,
or a bug.
```
// missing a break at 8080
switch (port) {
  case 8080:
    // no break so continues into the next case.
    // fallthrough.
  case 80:
    printf("Port http\n");
    printf("Try to change this port to 443\n");
    break;
  case 443:
    printf("Port https\n");
    x = a + b;
    break;
  default:
    printf("The port is not yet in the list.\n");
    break;
}
```

Other use of `break` is to break out of a loop.
```
while (a < b) {
  a++;
  if (a > c)
    break; // breaks the while loop
  d = a + b;
}
```

And `continue` in a loop is to stop the loop and continue with the next
iteration.
```
for (i=0;i<100;i++) {
  scanf("%d", &a);
  if (a<=0)
    continue;
  printf("100 divided by %d is %5.2f\n", a, 100./a)
}
```

Here we see also a new format symbol `%5.2f` for float. A float can be
written as `%f`, but here it also specifies the width, and precision.


---
|[TOC](../../README.md) | [Prev](../02/README.md) |[Next](../04/README.md)|