#include <stdio.h>

void bug() {
  char x[4];
  scanf("%s",x);
}
int main() {
  bug();
}
