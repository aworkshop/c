#include "listen.h"
#include "logging.h"

int my_listen(int server_port, int backlog) {
    int sock_listening;

    /*************************************************************/
    /* create IPV4 TCP socket                                    */
    /*************************************************************/
    printf("Creating socket: internet, TCP, default protocol.\n");
    if ((sock_listening = socket( AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(-1);
    }
    printf("Socket file descriptor: %d.\n", sock_listening);

    /*************************************************************/
    /* bind socket to port on local                              */
    /*************************************************************/
    printf("Binding socket...\n");
    struct sockaddr_in name; 
    //Prepare the sockaddr_in structure
    memset(&name, 0, sizeof(name));
	name.sin_family = AF_INET;
	name.sin_addr.s_addr = INADDR_ANY;
	name.sin_port = htons( server_port );
    int bnd;
    if ((bnd = bind(sock_listening, (struct sockaddr *) &name, sizeof (name))) < 0) {
        perror("bind failed");
        close(sock_listening);
        exit(-1);
    } 
    printf("Binding done.\n");
    pr_sockaddr_in(name);
    

    /*************************************************************/
    /* listen                                                    */
    /*************************************************************/
    printf("Server wants to listen. Backlog is %d.\n", backlog);
    int l;
    if ((l = listen(sock_listening, backlog)) < 0) {
        perror("listen failed");
        close(sock_listening);
        exit(-1);
    }
    printf("Listening.\n");

    return sock_listening;
}