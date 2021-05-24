# Makefile

# Specify the compiler and assembler options.
compflags = -g -c -O1 -Wall
asmflags = --gstabs

# object files specific for this app
objects = 13_func.o 13_main.o

13_app: $(objects)
	gcc -o 13_app $(objects)

13_func.o: 13_func.c 13_func.h
	gcc $(compflags) -o 13_func.o 13_func.c

13_main.o: 13_main.c
	gcc $(compflags) -o 13_main.o 13_main.c

clean:
	rm $(objects) 13_app
