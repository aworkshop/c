
### 02_add.c

When compiling the previous example, you noticed warnings. The first one started with `01_add.c:1:1 ` and then you can read that something is missing, it is default `int` and it shows a `^` pointing to the `m` of `main() {` on the first line. So `1:1` indeed means the first line, first character. And we can add that to get a new first line of `int main(){`.

Compiling this gets now one warning less. But what is this? This `int` warning tells that the application returns an integer as exit value, and we will not use that for a while, but lets remember that this is a standard.

So for the other two warnings. These are for lines 3 and 4 and complaining that we are implicitly declaring the `printf` and `scanf` functions. So C doesn't like surprises, we have to explicitly declare these, and then it will not be a surprise anymore for the compiler when we are using printf and scanf. These two are declared for us in another file, a header file, provided with the compiler. The header name for these standard IO methods is `stdio.h`. And we then include that, before anything else.
```
#include <stdio.h>
```
Now you see the `#` at the start of the line. This indicates a pre-processor step. Where the pre-processor will, before compiling, replaces the pre-processor steps with their real values. And only then compiles the C code.

There are also `< >` around the `stdio.h` standard-io-header file. And that indicates that it is part of the set of header files that are provided by the compiler installation. Later we see that we can also include our own header files, and these are then surrounded by normal double quotes.

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

One thing left to do. We need to start `./a.out`, but there is an option to the gcc compiler to directly create the proper output name.
```
$ gcc 02_add.c -o add
```
Then we can execute the application using `./add`.

Note, do not type anything else than whole numbers as input, because unexpected things can happen... There is no input validation.
