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

### 02_add.c

When compiling the previous example, you noticed warnings. The first one started with ```01_add.c:1:1``` and then you can read that something is missing, it is default ```int``` and it shows a ```^``` pointing to the ```m``` of ```main() {``` on the first line. So ```1:1``` indeed means the first line, first character. And we can add that to get a first line of ```int main(){```.
Compiling this gets now one warning less. But what is this? This ```int``` tells that the application returns an integer as exit value, and we will not use that for a while, but lets remember that this is a standard.
So for the other two warnings. These are for lines 3 and 4 and complaining that we are implicitly declaring the printf and scanf. So C doesn't like surprises, we have to explicitly declare these, and then it will not be a surprise anymore when we are using printf and scanf. These two are declared for us in another file, a header file, provided with the compiler. The header name for these standard IO methods is ```stdio.h```. And we then include that, before anything else.
```#include <stdio.h>
```
Now there is the ```#``` at the start of the line. This indicates a pre-processor step. Where the compiler will, before processing (compiling), replaces the pre-processor lines with their real values. And only then compiles the C code.
There are also ```< >``` around the ```stdio.h``` standard io header file. And that indicates that it is part of the set of header files that are given by the compiler. Later we see that we can also include our own header files, and these are then surrounded by normal double quotes.
Compiling the changed code now doesn't give warnings anymore.
One thing left to do. We need to start ```./a.out``` and there is option to the gcc compiler to directly create the proper output name.
```gcc 02_add.c -o add
```
Then we can execute the application using ```./add``` like before.
Note, do not type anything else than whole numbers as input, because unexpected things can happen.
