## 04_echo.c

This code is just showing two other functions that are in the stdio.h header.

```
#include <stdio.h>

int main() {
  char ch;
  do {
    ch = getchar();
    putchar(ch);
  } while(ch != '?');
  putchar('\n');
}
```

The while loop stops at the question mark. But you notice that the terminal
was waiting for the enter key before it started processing the input.

```
$ gcc 04_echo.c -o put
$ ./put
When will it stop? It stopped already!
When will it stop?
$
```

Please have a look what is defined in this stdio.h.
(https://en.wikipedia.org/wiki/C_file_input/output)
