#include <stdio.h>

// here are other functions
#include "func.h"
// compiler now knows what 'answer' is

int main() {
  int a = answer(); 
  printf("%d.\n", a ); 
}
