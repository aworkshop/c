#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen memset strcat
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/errno.h>
#include <arpa/inet.h> // inet_ntop & inet_pton
#include <unistd.h> //access getcwd FILENAME_MAX
#include <sys/param.h> // MAXPATHLEN
#include <sys/stat.h> // struct stat 

#include "listen.h"
#include "logging.h"
#include "receive.h"
#include "send.h"

/* http://localhost:8888 */
#define SERVER_PORT 8888
/* Listen backlog */
#define BACKLOG 5



int sock_listening;

/* Ctrl-C handler */
void SIGINT_callback_handler(int signal_num){
    printf("Stopping the server...\n\n");
    //Release the port
    close(sock_listening);
    shutdown(sock_listening, 2);
    // TODO memory?

    //exit program
    exit(0);
}



int main(void) {
 
    //register handler for Ctrl + C
    signal(SIGINT, SIGINT_callback_handler);
  
    sock_listening = my_listen(SERVER_PORT, BACKLOG);

    /*************************************************************/
    /* TODO set to non-blocking connection                       */
    /*************************************************************/

    // using Linux or Unix
    // but then the accept/recv/write loop will differ
    // and the client_sock can be -1 if there is not one


    /*************************************************************/
    /* next socket of the BACKLOG                                */
    /*************************************************************/
    for (;;) { // forever


    /*************************************************************/
    /* accept incoming connection                                */
    /*************************************************************/
	puts("Waiting for incoming connection(s)...");
	int c = sizeof(struct sockaddr_in);

	struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
	int client_sock; // a new one
    // accept is default a blocking operation
	if ((client_sock = accept(sock_listening, (struct sockaddr *)&client, (socklen_t*)&c)) < 0) {
		perror("accept failed");
        close(sock_listening);
        exit(-1);
	} 
    printf("Connection accepted: %d\n", client_sock);
    pr_sockaddr_in(client);


    /*************************************************************/
    /* receive the request                                       */
    /*************************************************************/
    struct request req = receive(client_sock);


    /*************************************************************/
    /* handle the request                                        */
    /*************************************************************/
    handle(client_sock, req.verb, req.url);
    

    free(req.message);
    free(req.line);
    close(client_sock);

    /*************************************************************/
    /* next socket of the BACKLOG                                */
    /*************************************************************/
    //printf("Next socket?\n");

    } // end for

}

