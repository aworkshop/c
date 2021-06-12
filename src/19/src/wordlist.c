#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
// source for ubuntu docker

// nr of characters
#define SIZE 3
// first printable char
#define START ' '
// last printable char
#define END '~'

/*
 * increment the buffer; use that as 'counter', but
 * it counts not from 0..9 but by characters in 
 * the start..end. The len specifies the length
 * in the buf. The buf must already contain
 * initial len*start values, and it must
 * already be null terminated.
 * Suppose 099, then pos will go to the 0 and
 * that is set to 1, and then the 99 will be
 * reset to 00, so resulting in 100.
 * When result is -1 stop.
 */
int inc(char* buf, int len, int start, int end) {
    int pos = len-1;
    while (pos>=0 && buf[pos]==end) {
      pos--; // determine pos to increment
    }
    if (pos>=0) {
        // increment this char
        buf[pos] = buf[pos] + 1;
        // reset these chars
        for (int i=pos+1;i<len;i++) {
            buf[i]=start;
        }
    } 
    return pos;
}
void init(char* buf, int len, int start) {
    memset(buf, start, len);
    buf[len] = '\0';    
}

char buf[SIZE+1];
unsigned char digest[MD5_DIGEST_LENGTH];

int main(void) {
    int i;
    init(buf, SIZE, START);
    while (inc(buf,SIZE,START,END)>=0) {
        MD5(buf, strlen(buf), digest);
        for(i = 0; i < MD5_DIGEST_LENGTH; i++)
            printf("%02x", digest[i]);
        printf(" %s\n", buf);
    }
    return EXIT_SUCCESS;
}
