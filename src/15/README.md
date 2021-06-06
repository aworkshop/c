## 15/enum.c

This code shows enum examples. And it results in this output

```
$ ./enum 
Port 80 is used.
Port 8080 is used.
Ports 0x17, size 4.
Ports 0x07, size 4.
On
West is 270 degrees.
```

Let us look at some lines;
```
enum off_on {Off, On};
enum boolean {false, true}; // false 0, true 1
```
Two enums and their values. 
Technically the values are handled as int. 
The first value is gets `0`, second value `1` and so on.

```
enum days {Mon, Tue, Wed, Thu, Fri, Sat, Sun};
enum wind {East=90, West=270, North=0, South=180};
```
More enums, but in the `wind` the int values are assigned. 
Note that these int values don't need to be unique.

```
enum settings {
  PORT80 = 1,
  PORT443 = 2,
  PORT8080 = 4,
  PORT8000 = 8,
  PORT22 = 0x10
} ports;
```
This enum uses the int (32 bits) values that represent a single bit. 
So these are powers of 2; `1, 2, 4, 8, 16, 32, 64, 128, ...`.
It now can be used to store 32 on/off settings in a single `int`.

```
  ports = PORT80 | PORT22 | PORT8080;
  if (ports&PORT80) { 
    printf("Port 80 is used.\n");
  }
```
This code is using that trick. It `|` ORs three values and stores that in 
a single int. Expression is `&` ANDing it with the enum value to know if 
that enum value is in the int.
The expression results in the value `PORT80` or `0`. A boolean expression
is `0` for a false and anything else for true. So it works.

```
  if ((PORT8080 & ports) == PORT8080) { 
    printf("Port 8080 is used.\n");
  }
```
This code is also using that trick. But it does a proper compare
so it is a boolean expression.

```
  ports |= PORT443;
  ports &= ~PORT22;
```
Add `PORT443` to the ports, and remove `PORT22` from ports.

```
  enum off_on light = On;
  switch(light) {
    case On:
      printf("On\n");
      break;
    case Off:
      printf("Off\n");
      break;
  }
```
Since the enum values are int values, the switch-case can be used nicely.

```
  printf("West is %d degrees.\n", West);
```
The enum value can also be used to print its int value.


## Using #define

Instead of using enum, `#define` can be used similar.

```
#define ON 1
#define OFF 0
```

But enum types are better readable, there is less chance of creating a bug (because
instead of using int values for everything, it is more restricted).
```
  int dir = West;
  enum wind w1 = West;
  enum wind w2 = On;     // compiler warning!
```
---