#include <stdio.h>
#include <sys/param.h> // MAXPATHLEN
#include <unistd.h> //access getcwd FILENAME_MAX
#include <string.h> // strlen memset strcat

#include "logging.h"

#ifndef SEND_H
#define SEND_H

#define FILE_BUF 1024
#define INDEX_HTML "index.html"

void handle(int client_sock, char* verb, char* url );

void localpath(char* path, char* url);
void resp404(int client_sock);
void resp(int client_sock, char* header, char* payload);
void respOKhdr(int client_sock);
void respfile(int client_sock, char* path);


#endif