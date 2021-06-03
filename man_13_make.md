## make (without Makefile)

We saw that the gcc compiler does the pre-compile, compile, assembler and linker.
But for more advanced builds, the `make` tool is used.

```
make 02_add
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
objects = 13_func.o 13_main.o

13_app: $(objects)
  gcc -o 13_app $(objects)
  echo 'Built the 13_app'

13_func.o: 13_func.c 13_func.h
	gcc $(compflags) -o 13_func.o 13_func.c

13_main.o: 13_main.c
	gcc $(compflags) -o 13_main.o 13_main.c

clean:
	rm $(objects) 13_app
```

The `make` scans the targets and their dependencies. It is efficient,
in that it will skip building targets if its dependencies did not change.
If one file was edited, it will only build the target(s) that depend on it
directly or indirectly.

You also see that there is a `make clean` target, that removes the target
executable, and intermediate files.

```
$ make
gcc -g -c -O1 -Wall -o 13_func.o 13_func.c
gcc -g -c -O1 -Wall -o 13_main.o 13_main.c
gcc -o 13_app 13_func.o 13_main.o

$ ls -l 13*
-rwxr-xr-x  1 rene  staff  8832 25 mei 00:24 13_app
-rw-r--r--  1 rene  staff    81 24 mei 23:50 13_func.c
-rw-r--r--  1 rene  staff    87 24 mei 23:38 13_func.h
-rw-r--r--  1 rene  staff  1852 25 mei 00:24 13_func.o
-rw-r--r--  1 rene  staff   125 25 mei 00:12 13_main.c
-rw-r--r--  1 rene  staff  2032 25 mei 00:24 13_main.o

$ ./13_app
42.

$ make clean
rm 13_func.o 13_main.o 13_app

```
