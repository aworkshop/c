## 06/increment.c

Now it becomes interesting.
```
i = 0;
a = (i++)*5;
b = (++i)*5;
```
What are a and b?

For a, we see that i is 0, so a is 0, but after (!) that i is incremented by 1.

For b, we see that i is 1 because it was incremented in the previous statement,
and it has `++i` so it is incremented before (!) the expression, so i becomes 2, so b is then 10.

```
$ ./increment 
The result is 0.
The result is 10.
```

The `++` and `--` have higher priorities than even `* / % `, so it is not required to have it within brackets.

Would this following code work? **No**. The compiler doesn't know what to set to i in the last line (which of the 3 i's will when be incremented?).
```
i = 0;
i += i+++++i;
```

To test the first increment option we compile and run;
```
#include <stdio.h>

int main() {
  int i = 0;
  int a = (i++)*5;
  int b = (++i)*5;
  printf("The result is %d.\n", a);
  printf("The result is %d.\n", b);
}
```
It results in;
```
$ ./increment
The result is 0.
The result is 10.
$
```


## 06/bits.c

Unfortunately there is no format string that prints binary output,
but octal and hexadecimal can show us what the operators do.

```
#include <stdio.h>

int main() {
  int i = 0x0F;
  int j = 0x08;
  int k = 0x10;
  int l = 0x11;
  int s = 2;

  printf("The result of %02X & %02X is %02X.\n", i, j, i&j);
  printf("The result of %02X | %02X is %02X.\n", i, k, i|k);
  printf("The result of %02X ^ %02X is %02X.\n", i, l, i^l);
  printf("The result of %02X << %02X is %02X.\n", k, s, k<<s);
  printf("The result of %02X >> %02X is %02X.\n", k, s, k>>s);
  printf("The result of ~%02X is %0X.\n", l, ~l);

}
```

The output of running this code is (values are hexadecimal);
```
The result of 0F | 10 is 1F.
The result of 0F ^ 11 is 1E.
The result of 10 << 02 is 40.
The result of 10 >> 02 is 04.
The result of ~11 is FFFFFFEE.
```

In this example we also saw a format string `%02X` this is hexadecimal in
capitals and 2 wide with leading zeroes.

We see that int is 4 bytes (the hexadecimal is 8 characters) on this system.
The `limits.h` has limits defined.