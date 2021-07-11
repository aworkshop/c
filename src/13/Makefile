# Makefile

# Specify the compiler options.
compflags = -g -c -O1 -Wall

# object files specific for this app
objects = func.o main.o 

app: $(objects)
	gcc -o app $(objects)

func.o: func.c func.h
	gcc $(compflags) -o func.o func.c

main.o: main.c
	gcc $(compflags) -o main.o main.c

clean:
	rm -fv $(objects) app
