## 07/createfile.c

This is a first more practical tool. Do you want to create a file with a specific size, like 10 Mb?

```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
      printf("Usage: %s <size> <filename>\n", argv[0]);
      exit(1);
    }
    long size = atol(argv[1]);
    char *name = argv[2];
    printf("Sizing %ld to %s.\n", size, name);

    FILE *fp; 
    fp = fopen(name, "w");
    fseek(fp, size-1, SEEK_CUR);
    fputc('\0', fp);
    fclose(fp);

    return 0;
}
```


Line 4 shows two parameters that are passed from
the command line to the program. The first is an
argument count, and the second is an argument value
array of strings. In this array, the first
argument `argv[0]` is the executable name itself.
So on line 5 we check if the argument count is correct. And it prints a Usage when not.

Lines 9 is taking the next argument and converts it to a long using the `atol()` function. Line 10 assigns the name to the last argument, this `char *` is a string. And line 11 prints it, where format specifier `%ld` is long decimal and `%s` is string.

Lines 13..17 creates the file with the given size and name.

Line 13 defines the file pointer, line 14 assigns it after it opened the file name for writing. Then on line 15 it seeks the file pointer to a specific offset in the file. And on line 16 it just writes a single null character. It then closes the file on line 17.

So is this fast? What does it create?

```
$ gcc 07_createfile.c -o createfile
$ time ./createfile 100000000 test
Sizing 100000000 to test.

real	0m0.005s
user	0m0.001s
sys	0m0.003s
$ ls -l test
-rw-r--r--  1 rene  staff  100000000 20 mei 22:24 test
$
```

Here we see it created a file of 100 MB in 5 millisec.
