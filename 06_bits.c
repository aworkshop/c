#include <stdio.h>

int main() {
  int i = 0x0F;
  int j = 0x08;
  int k = 0x10;
  int l = 0x11;
  int s = 2;

  printf("The result of %02X & %02X is %02X.\n", i, j, i&j);
  printf("The result of %02X | %02X is %02X.\n", i, k, i|k);
  printf("The result of %02X ^ %02X is %02X.\n", i, l, i^l);
  printf("The result of %02X << %02X is %02X.\n", k, s, k<<s);
  printf("The result of %02X >> %02X is %02X.\n", k, s, k>>s);
  printf("The result of ~%02X is %0X.\n", l, ~l);

}
