#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[] = "Hello";  // is [6] and includes \0
    char str2[] = "Bye";    // is [4] and includes \0
    char str3[100]; // buffer of 99 + \0 to close the string
    char *strp;     // pointer to char

    int c = strcmp(str1, str2); // compare str1 with str2
    if (c == 0) { 
        strp = "equals";
    } else if (c < 0) {
        strp = "less";
    } else {
        strp = "more";
    }

    strcpy(str3, "Comparing: "); // copy into str3
    strcat(str3, str1);          // concatenate 
    strcat(str3, " is ");
    strcat(str3, strp);
    strcat(str3, " than ");
    strcat(str3, str2);          // make sure it fits within 99 chars!
    fprintf(stdout, "%s. %d\n", str3, c);

    // length of string
    int len = strlen(str3);

    // tokenize using separators string
    // it changes the string! so copy it first if you don't want that.
    char sep[] = " "; // separator is a space
    strp = strtok(str3, sep);
    while( strp != NULL ) {
        fprintf(stdout, "* %s\n", strp);
        strp = strtok( NULL, sep); // reentrant!
    }
    fprintf(stderr, "The string was %d and is now %d long.\n", len, (int)strlen(str3));
}

// string.h strcmp(), strcpy(), strcat(), strlen(), strtok()
// fprintf() to stderr and stdout 