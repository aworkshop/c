#include <stdio.h>
#include <sys/socket.h> // AF_INET
#include <netinet/in.h> // struct sockaddr_in, INET_ADDRSTRLEN
#include <arpa/inet.h> // inet_ntop & inet_pton htons
#include <stdlib.h> // exit
#include <string.h> // strlen memset
#include <unistd.h> // write close

#ifndef LISTEN_H
#define LISTEN_H
int my_listen(int server_port, int backlog);

#endif