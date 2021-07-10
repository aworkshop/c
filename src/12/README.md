## stack, heap, global

Variables and data are stored in one of three spots.

| Memory | Notes | Problems |
| ---    | ---   | ---     |
| static | Global variables (declared outside functions), and all marked `static`. | - |
| stack  | Local variables in a function. Cleared when exiting the function. | Can lead to stackoverflow. |
| heap   | Large, use `malloc()` and `free()` and pointers. | Memory leak when memory is not freed.|


Fragment:
```
int myGlobal;                                // initialized to 0

int main() {
  static int myGlobal2;
  int myLocal;                               // not initialized
  char myStack[10];
  char *myLocalToHeap;

  myLocalToHeap = malloc(100*sizeof(char)); // memory allocation
  myLocalToHeap[0]='m';
  free(myLocalToHeap);                      // free memory allocation
}
```

## Stack

What is a stack? A stack is like a pile of papers. You start without. When you
call a function, the variables of that function are pushed to the stack. And
when you leave the function, the variables are popped from the stack.

When you call a function, it also needs to know where to return to, when it
leaves the function. So also the return address is pushed to and popped from
the stack.


## Buffer overflow

In C, strings are character arrays that are null character terminated.
Standard functions do not always check for boundaries. So you can put too-much
in there. This overflows the buffer. And overwrites other information.

This can then overwrite return addresses pushed to the stack, for example.

## Segmentation fault

Code with input is interesting to fuzz. In this code we can input a string
with a size of 4 including the `\0` byte.
```
#include <stdio.h>

void bug() {
  char x[4];
  scanf("%s",x);
}
int main() {
  bug();
}
```

When passing more than that, the application can crash. In this case at a
string of 12 length.
```
$ ./a.out
AAAAAAAAAAA
$ ./a.out
AAAAAAAAAAAA
Segmentation fault: 11
$
```

When you get this segmentation fault, then the application can be vulnerable.

Read more on this;
https://insecure.org/stf/smashstack.html


## Advanced / Assembly starter
Machine code, assembler language (asm), mnemonics.
Opcode with operands.

```
$ gcc 12/overflow.c
```

Look at the objdump and add the option to inline the C source with the
assembler. Fragment of the two functions;
```
_bug:
100000f50:	55 	pushq	%rbp
100000f51:	48 89 e5 	movq	%rsp, %rbp
100000f54:	48 83 ec 10 	subq	$16, %rsp
100000f58:	48 8d 75 fc 	leaq	-4(%rbp), %rsi
100000f5c:	48 8d 3d 4b 00 00 00 	leaq	75(%rip), %rdi
100000f63:	b0 00 	movb	$0, %al
100000f65:	e8 24 00 00 00 	callq	36 <dyld_stub_binder+0x100000f8e>
100000f6a:	89 45 f8 	movl	%eax, -8(%rbp)
100000f6d:	48 83 c4 10 	addq	$16, %rsp
100000f71:	5d 	popq	%rbp
100000f72:	c3 	retq
100000f73:	66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)
100000f7d:	0f 1f 00 	nopl	(%rax)

_main:
100000f80:	55 	pushq	%rbp
100000f81:	48 89 e5 	movq	%rsp, %rbp
100000f84:	e8 c7 ff ff ff 	callq	-57 <_bug>
100000f89:	31 c0 	xorl	%eax, %eax
100000f8b:	5d 	popq	%rbp
100000f8c:	c3 	retq
```

Only a few;

- nop is no-operation (used to fill code)
- push is pushing to the stack
- pop is popping from the stack
- mov is moving from, to
- add is adding
- sub is substracting
- nop is no-operation
- call is calling a system method (like printf etc)
- xor is the xor operation (when both operands are the same it clears it)
- lea is load effective address
- jz  is jump when zero (after calculation)
- jnz is jump when not zero (after calculation and ZF zero flag is cleared)
- retq is return to address popped from stack

So (%r.. are processor registers);
- pushq %rbp ; pushes 64 bit base pointer to the stack
- movq %rsp, %rbp; moves 64 bit stack pointer to the base pointer
- subq	$16, %rsp; substracting 16 from the stack pointer (stack grows down)


### change program flow?

You can change a JNE to JE or JNZ to JZ, so find the byte(s) for that 
and change.   



---
|[TOC](../../README.md) | [Prev](../11/README.md) |[Next](../13/README.md)|