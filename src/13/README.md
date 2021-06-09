## make (without Makefile)

We saw that the gcc compiler does the pre-compile, compile, assembler and linker.
But for more advanced builds, the `make` tool is used.

```
cd 02
make add2
```

It checks if there is a `Makefile` present in the current folder. Suppose
there is *not* one. Then it automatically looks for the `.c` file and builds
the executable with the same name using the `-o` option.

## make (with Makefile)

The following automatically loads the `Makefile` or `makefile` and makes it.
```
make
```

So what is in that file? In our file it has comment lines and assignments,
and there are `target: dependencies` followed by zero or more lines starting
with a tab character and linux commands.

```
# Makefile

# Specify the compiler and assembler options.
compflags = -g -c -O1 -Wall
asmflags = --gstabs

# object files specific for this app
objects = func.o main.o

app: $(objects)
	gcc -o app $(objects)

func.o: func.c func.h
	gcc $(compflags) -o func.o func.c

main.o: main.c
	gcc $(compflags) -o main.o main.c

clean:
	rm $(objects) app

```

The `make` scans the targets and their dependencies. It is efficient,
in that it will skip building targets if its dependencies did not change.
If one file was edited, it will only build the target(s) that depend on it
directly or indirectly.

You also see that there is a `make clean` target, that removes the target
executable, and intermediate files.

```
$ make
gcc -g -c -O1 -Wall -o func.o func.c
gcc -g -c -O1 -Wall -o main.o main.c
gcc -o app func.o main.o

$ ls -l 13*
-rw-r--r--  1 rene  staff   344  5 jun 13:51 Makefile
-rwxr-xr-x  1 rene  staff  8840  5 jun 13:52 app
-rw-r--r--  1 rene  staff    59  5 jun 13:51 func.c
-rw-r--r--  1 rene  staff    87  5 jun 13:50 func.h
-rw-r--r--  1 rene  staff  1852  5 jun 13:52 func.o
-rw-r--r--  1 rene  staff   122  5 jun 13:51 main.c
-rw-r--r--  1 rene  staff  2032  5 jun 13:52 main.o

$ ./app
42.

$ make clean
rm func.o main.o app
```


---
|[TOC](../../README.md) | [Prev](../12/README.md) |[Next](../14/README.md)|