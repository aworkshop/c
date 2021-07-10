
#include "receive.h"


struct request receive(int client_sock) {

    struct request req;

    /*************************************************************/
    /* receive data from the client                              */
    /*************************************************************/	
    int recv_size;
    char buffer[BUFFER_SIZE]; // fixed receive buffer
    memset(buffer, BUFFER_SIZE, sizeof(char));

    int already_recvd = 0; // chars received
    int already_copyd = 0; // chars copied
    // growing message is (re)allocated over and over
    req.message = malloc( already_recvd+1 );

    // get next block into buffer
    // except for the last byte (BUFFER_SIZE-1); keep that as \0
    // while there are bytes received
	while( (recv_size = recv(client_sock , buffer , BUFFER_SIZE-1 , 0)) > 0 ) {

        // extend message with recv_size 
        already_recvd += recv_size;
        // add +1 char to be set to \0 later
        char *larger_message = realloc(req.message, already_recvd+1 );
        if (larger_message == NULL ) {
            fprintf(stderr, "realloc failed");
            close(sock_listening);
            close(client_sock);
            free(req.message);
            exit(EXIT_FAILURE);
        }
        req.message = larger_message;

        // append buffer to null-terminated message
        memcpy(req.message + already_copyd, buffer, recv_size);
        already_copyd += recv_size;
        req.message[already_copyd] = '\0'; 

        // stats
        printf("received %d, total %d \n", recv_size, already_copyd);

        // break if last block read
        // assume last when read less than requested
        if (recv_size < BUFFER_SIZE-1) {
            break; // while recv()
        }

        // test for max message
        if (already_copyd > MAX_MESSAGE) {
            fprintf(stderr, "max message reached, so stopped");
            close(sock_listening);
            close(client_sock);
            free(req.message);
            req.message = NULL;
            exit(EXIT_FAILURE);            
        }
    }


    // Next part can be removed? It is just checking the header lines.


    // find the end of the http header
    char* end = strstr(req.message, "\r\n\r\n");
    if (end == NULL) {
        // end of http header not found!
        fprintf(stderr, "WARNING: End of header not found!\n");
        close(sock_listening);
        close(client_sock);
        free(req.message);
        req.message = NULL;
        exit(EXIT_FAILURE);
    } else {
        // set to after the header and two empty lines
        end += strlen("\r\n\r\n");
    }
    // TODO do something with header
    // that ends with char*end
    
    // TODO do something with other content
    printf("Size header %ld, Size total %ld\n",(end-req.message), strlen(req.message));


    // find the end of the first http header line
    char *eol = strstr(req.message, "\r\n"); // assume 
    if (eol!=NULL) {
        // found, so now work with it.
        int len = eol-req.message;
        req.line = calloc(len + 2, sizeof(char));
        memcpy(req.line, req.message, len);
        req.verb = strtok(req.line, " ");
        req.url = strtok(NULL, " ");

        printf("Verb %s\nUrl  %s\n",req.verb, req.url);
        // TODO free(req.line) to avoid memory leak!
    }

    return req;
}
