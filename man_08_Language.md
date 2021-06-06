# Theory (part 3)

## Contents

This theory section contains:
- Arrays and Pointers
- Function arguments passed "by value"
- Function arguments passed "by reference"

Advanced
- Pointer mis-use


## Arrays and Pointers

An array declaration `int x[10];` means that we can now use `x[0]` up to `a[9]`, so 10 elements.

A pointer contains the address of an element.

To clarify this, let us assume we are looking at computer memory addresses and the values on each address.

```
Address Value
0000    13
0001    42    
0002    91     <-- variable: int v = 91
0003    86
```

Suppose `p` is a pointer to `v`. This means that `p = & v`, p is the address of v. That means that `p` has value `2`.

Of course we can assign a new value to `v`, but we can also do that now via `*p = 16;` the object at `p` becomes 16. So does `v`!

Try to memorize; that & is the 'Address of' and * is the 'Object (at address)'.

```
int v, *p; // declare integer v, and pointer p to integer
v = 91;    // the integer v becomes 91
p = &v;    // the pointer p gets the address of v
*p = 16;   // the object at p becomes 16
printf("%d", v); // prints 16
```

Now what are arrays and pointers got to do with each other?

```
int x[10], *p;
x[0]   = 1;

*x     = 1;   // same as x[0] = 1
*(x+1) = 5;   // same as x[1] = 5
*(x+2) = 4;   // same as x[2] = 4
p = x;        // x and p are both pointers to int
print("%d", ++p);  // prints x[1] so 5
```

Warning: it is easy to make a mistake, like `x[10] = 1;` because `x[9]` is the last element.

### example 08/arrays.c

Example 08/arrays.c contains some bugs. 
* bug 1 = string is not finished with '\0' byte.
* bug 2 = pointer to string calculation is wrong
* bug 3 = use uninitialized array on the stack


### void pointer

A `(void *)` is a void pointer, it means that it is a pointer to
anything. Can point to integer or char, etc. Cast it back to use it.



## Function arguments passed "by value"

A function is called with a variable or constant.
The function uses these argument vars locally within the function.
Any change is also only locally, while the function runs.
So the *value* is passed to the function.
```
my_function( i );
my_function( 42 );
```


## Function arguments passed "by reference"

A function is called with the address (=pointer) to a variable.
The function can use and even *change* the original value.
So the *reference* is passed to the function.
```
#define SIZE 100
char buffer[SIZE];
int i = 21;
times_two( &i );
fill_buffer( buffer, SIZE );
```



## Pointer mis-use

What could happen if you make a mistake?
Let us look at memory addresses again;
```
int a, b, y[3], c, *p;
p=y;
*(p+3) = 42;  // error; because it is c in the example below

Address int (4 bytes)
0000    0     <-- a
0004    0     <-- b
0008    0     <-- y[0]
000C    0     <-- y[1]
0010    0     <-- y[2]
0014    42    <-- c
0018    ?     <-- ?
```

Newer languages than C often stop you from doing things like this.

Why is it allowed in C? This flexibility is very powerful.
It is very fast, passing pointers to memory blocks instead of the blocks completely themselves.
And, not all addresses in a computer are memory, some addresses are used for hardware like ports and video.


### Attack

A call to a function means the system needs to know _where to continue after the call_. So it pushes the program_counter to the stack.
And the function arguments are pushed to the stack.
At the end of the function, it pops these from the stack.
And it pops the program_counter from the stack, and so continues where it left of.

Because the program_counter and arguments are stored very close to each other in the stack memory, it is vulnerable that a bug can a change the program_counter.
And then the program can pop the altered program_counter from the stack. And continues to run there.

An attacker could try to take advantage of this.
Input normal data, but hide also compiled code in it.
Alter the program_counter to point to your compiled code.
