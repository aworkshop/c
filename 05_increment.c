#include <stdio.h>

int main() {
  int i = 0;
  int a = (i++)*5;
  int b = (++i)*5;
  printf("The result is %d.\n", a);
  printf("The result is %d.\n", b);
}
