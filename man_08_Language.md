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


**Advanced**

What could happen? Let us look at memory addresses again;
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

Newer languages than C often stop you from doing things like this. But this flexibility is also very powerful. Not all addresses in a computer are memory, some addresses are used for hardware like ports and video.
