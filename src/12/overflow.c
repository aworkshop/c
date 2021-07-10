#include <stdio.h>

void bug() {
  char x[4];
  scanf("%s",x);
}

int main() {
  puts("Type in more than 3 chars to overflow the array.");
  bug();
}
