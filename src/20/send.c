#include "send.h"

void handle(int client_sock, char* verb, char* url ) {

    char path[MAXPATHLEN+1];
    localpath(path, url);

    if (strcmp("GET", verb) == 0) {
        // GET

        // file exist?
        if (access(path, F_OK) == 0) {
            check(path);
            respfile(client_sock, path);
            printf("Response from file written.\n");
        } else {
            // requested file (url) doesnt exist
            printf("File doesnt exist %s\n", path);
            resp404(client_sock);
        }
        // end GET
    } else {
        printf("No GET, but a %s\n", verb);
    }
}

void localpath(char* path, char* url) {

    getcwd(path, MAXPATHLEN);
    printf("Current working directory: %s\n", path);

    strcat(path, "/www");
    strcat(path, url);
    if (strlen(path)>0 && path[strlen(path)-1]=='/') {
        strcat(path, INDEX_HTML);
    }
    printf("Local: %s\n", path);
}

void resp(int client_sock, char* header, char* payload) {
    if (header!=NULL)
        write(client_sock, header, strlen(header));
    if (payload!=NULL)
        write(client_sock, payload, strlen(payload));
}

void respOKhdr(int client_sock) {
    char header[] =
        "HTTP/1.0 200 OK\r\n"
        "Server: HackDeWereld.nl\r\n"
        "Content-type: text/html\r\n"
        "\r\n"
    ;
    resp(client_sock, header, NULL);
}

// write file from path to the client_sock
void respfile(int client_sock, char* path){
    // header
    respOKhdr(client_sock);

    // body
    char buf[FILE_BUF+1];
    FILE *fp = fopen(path, "r");

    int l;
    while( (l= fread(buf, sizeof(char), FILE_BUF, fp)) > 0) {
        write(client_sock, buf, l);
    }

    if (feof(fp)) {
        fclose(fp);
    }        
}

void resp404(int client_sock){
    // write header back to browser client
    // HTTP/1.0 can be simpler than HTTP/1.1
    char header[] =
        "HTTP/1.0 404 OK\r\n"
        "Server: HackDeWereld.nl\r\n"
        "Content-type: text/html\r\n"
        "\r\n"
    ;
    char payload[] = 
        "<html>\
        <title>404</title>\
        <body>Not found.</body>\
        </html>"
    ;
    resp(client_sock, header, payload);
}
