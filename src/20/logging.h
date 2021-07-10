#include <stdio.h>
#include <string.h> // strlen
#include <sys/socket.h> // AF_INET
#include <netinet/in.h> // struct sockaddr_in, INET_ADDRSTRLEN
#include <arpa/inet.h> // inet_ntop & inet_pton htons
#include <sys/stat.h> // struct stat 
#include <stdlib.h>

#ifndef LOGGING_H
#define LOGGING_H
void pr_sockaddr_in(struct sockaddr_in s);
void prt(char*s, int len);
void check(char* path);

#endif