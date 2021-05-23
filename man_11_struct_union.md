## struct

A struct is a combination of multiple variables. Kind of an object in modern
languages, but without methods.

```
struct person {
  char name[20];
  char zip[6+1];     // 6 chars + a '\0' char
  char city[20];
  int age;
} s, t;

struct person u;
```

This declares a struct type ```person``` and ```s, t, u``` are declared to be
of that type. From then on the person type can be used again.

The variables can be used like this;
```
  s.age = t.age + 3;
  strcpy(s.name, "Maria");
```

The values can be initialized (when extern or static only);
```
static struct person {
  char name[20];
  char zip[6+1];
  char city[20];
  int age;
} s = {"Sara" , "1000AA", "Amsterdam", 50},
  t = {"John" , "5700DQ", "Rotterdam", 21};
```


## functions with struct

Suppose we want to sort two persons by age. We are actually use the
pointer (memory addresses) of the two persons as input and return
the pointer to the max as function result.

```
struct person *max(p, q)
  struct person *p, *q;
{ return (*p).age > (*q).age ? p : q;
}

// alternative to (*p).age rewritten to p->age

struct person *max(p, q)
  struct person *p, *q;
{ return p->age > q->age ? p : q;
}

```

Then this function can be used;
```
  printf("Oldest person is %d years.\n", max(&s, &t) -> age);
```


## declare and define functions and types

When using a function, it need _at least_ to be *declared* before it is used.
It can also be completely *defined* first. In C the order when things are
declared and defined is important.

```
// declare signature of 'answer'
int answer();

int main() {
  printf("%d.\n", answer() ); // compiler now knows what 'answer' is
}

// define the 'answer' function
int answer() {
  return 42;
}
```

## header files

Suppose that we split the above program into multiple source files.
So we can re-use the function in other code.

```
// func.h
int answer();
#define MAX 120
```
The header file is declaring.

```
// func.c
#include "func.h"
int answer() {
  return 42;
}
```
The source is defining.

```
#include "func.h"

int main() {
  printf("%d.\n", answer() ); // compiler now knows what 'answer' is
}
```
The main is using it.

For this short code this is not useful, but it will be when the application
grows.

## pre-processor defines

Using the pre-processor, it is possible to include or exclude code in
compilation.
```
#define PENSION_AGE 67
#define ADULT_AGE 18
#if ADULT_WORK_LIFE PENSION_AGE - ADULT_AGE < 50
  ...
#else
  ...
#endif


#ifndef MAX
#define MAX 120
#endif
```

Often header files have this pre-processor guard condition to make sure that
source is not included twice.

```
// func.h
#ifndef __FUNC_H__
#define __FUNC_H__

int answer();
#define MAX 120

#endif
```
So when the compiler already knows about ```__FUNC_H__``` then it skips
declaring it again.

## register

Declare an int with ```register``` to store this int in a processor register
instead of in a memory location. This can make the application faster.
Modern compilers probably already optimize for it.

## struct with bitfields

When I want to process a lot of information, and I have to efficiently
use memory, I can save space by specifying the number of bits.
```
struct {
  int id;
  unsigned adult: 1;
  unsigned vaccinated: 1;
  unsigned infected: 1;
} person[10000];

int main() {
  ...
  person[i].vaccinated = 1; // only 0 or 1
}
```
The bitfields don't have their own memory address, so no pointer.

## union

In case we want to store different things in the same memory, unions can be
used. It takes the _largest_ size. The different components _overwrite_
each other basically.

```
union weight {
  int babyPounds;
  float adultKilos;
  char userInput[8];
} u, *p;

...
u.adultKilos = 87.33;
p->userInput = "Unknown";
```

## typedef
Using ```typedef``` declare a type with a name.

```
typedef double MYREALTYPE;
MYREALTYPE a, b, c;

typedef char *STRING;
STRING name;

typedef struct {
  int age;
  char *name[20];
} PERSON;

PERSON john;
```
