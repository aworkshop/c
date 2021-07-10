#include "logging.h"


// prints errno
void pr_sockaddr_in(struct sockaddr_in s) {
    // get IP v4 in str
    char str[INET_ADDRSTRLEN+1];
    inet_ntop(AF_INET, &(s.sin_addr), str, INET_ADDRSTRLEN);
    str[INET_ADDRSTRLEN] = '\0';

    printf("len %d\tfamily %d\tip:port %s:%d\tzero %s\n"
    , s.sin_len // unsigned char
    , s.sin_family // unsigned char
    , str // ip
    , s.sin_port // unsigned short
    , s.sin_zero); // char[8] 
}

// print buffer with len (no need for null terminated string)
void prt(char*s, int len) {
    printf("Received size %d\n", len);
    for (int i=0; i<len;i++) 
        putchar(s[i]);
}

// only log what it is
// can be extended for other types...
// consider delete it
void check(char* path) {
    struct stat *stt = calloc(1, sizeof(struct stat));
    int x = stat(path, stt);
    if (stt->st_mode & S_IFREG) {
        // regular file
        printf("Size regular file: %lld\n", stt->st_size);
    } else {
        printf("Not regular file...\n");
    }
    free(stt);
    stt = NULL;
}