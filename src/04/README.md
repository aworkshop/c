# Echo echo echo ...

## 04/echo.c

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
was waiting for the **enter key** before it started processing the input.

```
$ gcc echo.c -o put
$ ./put
When will it stop? It stopped already!
When will it stop?
$
```

Please have a look what is defined in this stdio.h.
* https://en.wikipedia.org/wiki/C_file_input/output
* `man stdio`



## 04/pin.c

This shows a bug; `( pin = 4321 )` is an assignment, wrapped as expression that evaluates to a true. If the `()` around the 
assigment are removed, then the compiler will warn you.

```
#include <stdio.h>

int main(void) {
  int pin = 1234;
  char *result;
  if ( ( pin = 4321 ) ) // bug
    result = "Correct";
  else 
    result = "Incorrect";
  printf("Pin is %s\n", result);
}
```

---
|[TOC](../../README.md) | [Prev](../03/README.md) |[Next](../05/README.md)|