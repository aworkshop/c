#include <stdio.h>
// ASCII table
char *shrt[]={
  "NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL",
  "BS","TAB","LF","VT","FF","CR","SO","SI",
  "DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB",
  "CAN","EM","SUB","ESC","FS","GS","RS","US"
};

int main(void) {
  printf("Dec Hex Char | Dec Hex Char | Dec Hex Char | Dec Hex Char | \n");

  for (int i=0;i<32;i++){
    printf(" %2d  %02X  %-3s |  %2d  %02X  %c   |  %2d  %02X  %c   | %3d  %02X  %c   | \n"
      ,i,i,shrt[i],
      i+32,i+32,i+32,
      i+64,i+64,i+64,
      i+96,i+96,i+96);
  }
  return 0;
}
