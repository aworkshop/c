## 14/folders.c using Ubuntu and Dockerfile and make

This is combining make, and Ubuntu running in Docker.

The following is using the makefile to build and run the code. This is really fast when Docker already downloaded the base image. 
```
$ make
```

How does this work?
- make uses the makefile
- makefile has a target that doesnt exist, so it always runs that
- a docker image is created using a Dockerfile
- it uses Ubuntu
- it installs gcc and other tools
- it copies the code into the image
- it compiles the code to an executable
- it defines the default command to execute
- the docker image is executed


### makefile

```
image:
	docker build -t folders .
	docker run folders
```


### Dockerfile

```
FROM ubuntu

RUN apt-get update && apt-get install -y \
  gcc \
  gdb \
  ltrace \
  nano \
  && rm -rf /var/lib/apt/lists/*

RUN groupadd -r grp && useradd -l -r -g grp app
COPY --chown=app:grp folders.c /app/
WORKDIR /app
USER app

RUN gcc folders.c -o folders
# the CMD can be overridden: docker run -it folders /bin/bash
CMD ["./folders", "."]
```


### How long does it run?
When the Ubuntu image is already downloaded, and the apt-get doesn't need an update, it is **1.3 seconds**.
The log lines with docker output are removed below.

```
$ time make
docker build -t folders .

... (removed) ...

docker run folders
R                  folders.c                809
D                          .               4096
D                         ..               4096
R                    folders              17048

real    0m1.306s
user    0m0.297s
sys     0m0.159s
$
```

Only to execute the built container image takes **0.6 seconds**.
```
$ time docker run folders
R                  folders.c                809
D                          .               4096
D                         ..               4096
R                    folders              17048

real    0m0.647s
user    0m0.124s
sys     0m0.058s
```


---
|[TOC](../../README.md) | [Prev](../13/README.md) |[Next](../15/README.md)|