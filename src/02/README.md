## Explaining 02/add1.c

This example is showing a couple of things that need our attention.
But it will work. This simulates what you might experience while coding.
```
main() {
  int a, b;
  printf( "Enter two numbers: " );
  scanf(  "%d%d", &a, &b );
  printf( "Sum: %d\n", a + b );
}
```
But let us just compile and run it first.
Open your terminal and compile and link it. 
It assumes you already have gcc; if you don't, look up the 'docker' lesson.

```
$ gcc add.c
```

This will show you warnings.
And when you `ls` this folder there is a new file `a.out`.
And that is already your executable.
You can run it by  `./a.out`.
You see a prompt, and then type two numbers like  `32 64` separated by a space
or by a new line. It then responds with the calculated sum  `96`.

When you look into the `add.c` file using a text editor like Atom,
VSCode, etcetera, you can see the line number before every line.
And that line number is used to discuss the code.

So line numbers 3 and 5 print formatted information, and line 4 is scanning
formatted information (our input).
You also see on line 4 and 5 this `%d`; used for the two numbers that are
scanned and the sum that is printed, and `d` is used to represent `int` decimal
integer values, defined on line 2.
There is also the `\n` on line 5 and this is just printing a newline character.

Line 4 also has `&a, &b` and this is the most difficult.
The `scanf` scans formatted input, according to its format parameter.
And stores the scanned values into the addresses of variables a and b.
Remember that `&a` is the address of `a`, or the pointer to `a`.
Scanf needs that address to change the value at that address.



### Explaining 02/add2.c

When compiling the previous example 1, you noticed warnings. 

The first one started with `add1.c:1:1 ` and then you can read that something is missing, it is default `int` and it shows a `^` pointing to the `m` of `main() {` on the first line. So `1:1` indeed means the first line, first character. And we can add that to get a new first line of `int main(){`.
Compiling this change gets now one warning less. But what is this? This `int` warning tells that the application returns an integer as exit value, and we will not use that for a while, but lets remember that this is a standard.

So for the other two warnings. These are for lines 3 and 4 and complaining that we are implicitly declaring the `printf` and `scanf` functions. So C doesn't like surprises, we have to explicitly declare these, and then it will not be a surprise anymore for the compiler when we are using printf and scanf. These two are declared for us in another file, a header file, provided with the compiler. The header name for these standard IO methods is 
`stdio.h`. And we then include that, before anything else.
```
#include <stdio.h>
```

Now you see the `#` at the start of the line. This indicates a *pre-processor* step. Where the pre-processor will, before compiling, replaces the pre-processor steps with their real values. And only then compiles the C code.

There are also `< >` around the `stdio.h` standard-io-header file. And that indicates that it is part of the default set of header files that are provided by the compiler installation. Later we see that we can also include our own header files, and these are then surrounded by normal double quotes.

Compiling the changed code now doesn't give warnings anymore.

```
#include <stdio.h>

int main() {
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d%d", &a, &b);
  printf("Sum: %d\n", a+b);
}
```

One thing left to do. We had to run `./a.out`, but there is an option to the gcc compiler to directly create the proper output name.
```
$ gcc add.c -o add
```
Then we can execute the application using `./add`.

Note, do not type anything else than whole numbers as input, because unexpected things can happen... There is no input validation.


## Advanced: the executable file

When looking on my file system using `ls -l` I see that the `a.out` is about **8 Kb** in size.
It contains all kind of binary code, debug information, but also the strings that you recognize from the source code.
Use the `strings` command;
```
$ strings a.out
Enter two numbers:
%d%d
Sum: %d
```

When looking at lines of the executable content, I use a hex-dump. This
shows the address, the bytes in hexadecimal and its character (when printable).
```
$ xxd a.out | head
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

$ xxd a.out | tail
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

$ file a.out
a.out: Mach-O 64-bit executable x86_64
```
The output depends on the operating system and processor.

