
## 06_bits.c

Unfortunately there is no format string that prints binary output,
but octal and hexadecimal can show us what the operators do.

The output of running this code is (values are hexadecimal);
```
The result of 0F | 10 is 1F.
The result of 0F ^ 11 is 1E.
The result of 10 << 02 is 40.
The result of 10 >> 02 is 04.
The result of ~11 is FFFFFFEE.
```

In this example we also saw a format string ```%02X``` this is hexadecimal in
capitals and 2 wide with leading zeroes.
We also see that int is 4 bytes on this system.
The ```limits.h``` has these limits defined.
