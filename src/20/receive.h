#include <stdio.h> // stderr
#include <string.h> // strlen memset memcpy
#include <stdlib.h> // malloc
#include <sys/socket.h> // recv
#include <unistd.h> // write close

#ifndef RECEIVE_H
#define RECEIVE_H

/* Client message buffer size */
#define BUFFER_SIZE 2000
/* Max incoming message size 100K */
#define MAX_MESSAGE 100000

struct request {
    char *message;
    char *line;
    char *verb;
    char *url;
};

struct request receive(int client_sock);

// defined in server.c
extern int sock_listening;

#endif