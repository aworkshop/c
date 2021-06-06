#include <stdio.h>

int main(void) {
  int pin = 1234;
  char *result;
  if ( ( pin = 4321 ) ) // bug
    result = "Correct";
  else 
    result = "Incorrect";
  printf("Pin is %s\n", result);
}
