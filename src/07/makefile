target: createfile
	./createfile 64 answer
	ls -l answer
	xxd answer
createfile: createfile.c
	gcc createfile.c -o createfile
clean:
	rm -fv createfile a.out answer
