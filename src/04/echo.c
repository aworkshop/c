#include <stdio.h>

int main() {
  char ch;
  do {
    ch = getchar();
    putchar(ch);
  } while( ch != '?' );
  putchar('\n');
}
