#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[] = "Hello";
    char str2[] = "Bye";
    char str3[100]; // buffer of 99 + \0
    char *strp;     // pointer
    int c = strcmp(str1, str2); // compare
    if (c == 0) { 
        strp="equals";
    } else if (c < 0) {
        strp="less";
    } else {
        strp="more";
    }
    strcpy(str3, "Comparing: "); // copy into str3
    strcat(str3, str1);          // concatenate 
    strcat(str3, " is ");
    strcat(str3, strp);
    strcat(str3, " than ");
    strcat(str3, str2);
    fprintf(stdout, "%s. %d\n", str3, c);

    // length of string
    int len = strlen(str3);

    // tokenize using separators string
    // it changes the string! so copy it if you don't want that.
    char sep[] = " ";
    strp = strtok(str3, sep);
    while( strp != NULL ) {
        fprintf(stdout, "* %s\n", strp);
        strp = strtok( NULL, sep); // reentrant
    }
    fprintf(stderr, "The string was %d and is now %d long.\n", len, (int)strlen(str3));
}

// string.h strcmp(), strcpy(), strcat(), strlen(), strtok()
// fprintf() to stderr and stdout 