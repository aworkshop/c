#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char myChars[] = {'a', 'b', 'c', ' '}; // missing null char
char myOther[] = "What happened?";

char myChars2[] = {'a', 'b', 'c', '\0'}; // null char
char myOther2[] = "Hello World";

char empty[10]; // initialized to 0
static char empty2[10]; // initialized to 0

char *p = myOther2;

/*
 * function with for loop
 */
void myFor(char*str) {
  for (int i=0; i<strlen(str); i++) {
    putchar(str[i]);
  }
  putchar('\n'); // to flush the line
}

/*
 * function with while loop
 * prints in upper case
 */
void myWhile(char*ptr) {
  while (*ptr != '\0') {
    putchar( toupper( *ptr++ ) );
  }
  putchar('\n'); // to flush the line
}
/*
 * function with uninitialized char array
 */
void myEmpty() {
  char charsNotInitialized[10];
  for (int i=0; i<10; i++)
    printf("%02x ", charsNotInitialized[i]);
  printf("\n");
}

/*
 * Main method. The output will be:
 'abc What happened?'.
 'abc'.
 Hello World
 HELLO WORLD
 WHAT HAPPENED?
 00 00 0a 00 00 00 3f 00 00 00
 */
int main(void){
  printf("'%s'.\n", myChars);
  printf("'%s'.\n", myChars2);

  myFor( myOther2 );
  myWhile( p   );

  myWhile( p -4 -15 ); // bug
  myEmpty(); // bug

  exit(EXIT_SUCCESS);
}

// shows more includes
// shows functions
// shows char array must end with '\0'
// shows string assignment already ends with '\0'
// shows char pointer, and increments
// shows char pointer calc, and problem with it
// shows while and for loops
// shows strlen, putchar and toupper
