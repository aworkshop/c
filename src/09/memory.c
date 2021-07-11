#include <stdio.h>
#include <stdlib.h>

#define BUFFER 1024
typedef unsigned char byte; // 0..255

int main(void) {
    byte b[BUFFER];
    printf("Address is %u\n", (unsigned int) b);

    char *c;
    c = (char *) malloc(BUFFER); // doesn't set the content to zeroes
    printf("Address is %u\n", (unsigned int) c);
    free(c);  // memory must be freed to avoid memory leaks
    c = NULL; 

    // if using same size, it might just return the same memory block
    c = (char *) calloc(BUFFER+1, sizeof(byte)); // sets it to zero
    printf("Address is %u\n", (unsigned int) c);
    free(c);  

    for (;;) { // forever
        // c = malloc(BUFFER); 
        // enable above to force memory leak on your own risk
    }
}
