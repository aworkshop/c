#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
// GET / example.com

int getTcpSocket() {
  // AF_INET is IP version 4
  // SOCK_STREAM is connection oriented TCP
  // Protocol 0 IPPROTO_IP is IP
  int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    puts("Couldn't create socket\n" );
    exit(1);
  }
  return socket_desc;
}

void resolveIP(char*hostname, char*ip){
  struct hostent *he;
  struct in_addr **addr_list;
  int i;
  if ((he=gethostbyname(hostname)) == NULL) {
    herror("gethostbyname");
    exit(1);
  }
  // cast h_addr_list to in_addr
  addr_list = (struct in_addr **) he->h_addr_list;
  for (i=0; addr_list[i]!=NULL; i++){
    // return first
    strcpy(ip, inet_ntoa(*addr_list[i]) );
  }
  printf("%s resolved to: %s\n", hostname, ip);
}

void connectIP(char*ip, int port, int socket_desc){
  struct sockaddr_in server;
  // convert IP to a long
  server.sin_addr.s_addr = inet_addr(ip);
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  // connect to server
  if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    puts("connect error");
    exit(1);
  }
  puts("Connected");
}

void getIndex(int socket_desc) {
  // send some data
  // HTTP/1.1 requires a Host: domain[:port]
  char *message = "GET / HTTP/1.1\nHost: example.com\r\n\r\n";
  if (send(socket_desc, message, strlen(message), 0) < 0) {
    puts("Send failed");
    exit(1);
  }
  puts(message);
  puts("Data sent\n");
}

#define BUF 2048
void receiveResp(int socket_desc) {
  char server_reply[BUF];
  if (recv(socket_desc, server_reply, BUF, 0) < 0) {
    puts("recv failed");
    exit(1);
  }
  puts("reply received\n");
  puts(server_reply);
}

int main(int argc, char *argv[]) {

  int socket_desc = getTcpSocket();

  char *hostname="example.com";
  char ip[100]; // buffer IPv4
  resolveIP(hostname, ip);

  connectIP(ip, 80, socket_desc);

  getIndex(socket_desc);

  receiveResp(socket_desc);

  close(socket_desc);
  return 0;
}
