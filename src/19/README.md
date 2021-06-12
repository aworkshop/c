
## 20/wordlist.c (md5 of all 3 character combinations)

Example of Docker with shared folder with the host. The docker image is 
having the compiler. The `src/` subfolder is shared with the image, 
and the compiler executes compiler and application.

Because the subfolder is shared, the end-result of the build and 
execution of the application is kept in that folder!

- use it to produce executables for other environments
- use it to produce data files.

This example generates a wordlist + md5.

I'm using a openssl development header file and library. And
require to install that `libssl-dev` in `apt-get`, see `Dockerfile`.

When compiling, I need to link my compiled object with `libcrypto`, 
like `gcc wordlist.c -lcrypto -o wordlist`.

- installed the libssl-dev
- linked the libcrypto

Build the docker container.
```
$ make
```
This uses the `Dockerfile` based on `ubuntu` then runs `apt-get` to install dependencies
etcetera. Then the container is run, sharing subfolder `src/`, so that 
the `src/wordlist.c` and the `src/makefile` are available in the container, and 
`make` is run on it. That produces the ubuntu executable `src/wordlist`.
And then it is executed, redirecting the stdout to `src/x`. And the container
run finished.

Now the subfolder `src/` contains the output of running the container! So we can use
that on the host.

What did the application do? 
It produces a wordlist with words that are of length 3 and have chars from ' ' to '~'.
These are only printable characters 0x20..0x7e, so 857375 combinations.
For each of these an md5 is calculated. The output then contains the md5 and word. 
So the file is ~ 31 Mb.

---
|[TOC](../../README.md) | [Prev](../18/README.md) |