# on host
image: clean
	docker build -t wordlist .
	docker run --rm -v ${PWD}/src:/app wordlist
	ls -l src/
	wc -l src/x
	
clean:
	rm -fv src/x src/wordlist
