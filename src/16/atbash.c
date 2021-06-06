
#include <stdio.h>
#include <stdlib.h>
// ATBASH reverse
// use stdin stdout
int main(void){
  int ch;
  while((ch=fgetc(stdin))!=-1) {
    if (ch>='A' && ch<='Z') { 
        fputc('A'+25-ch+'A', stdout);
    } else if (ch>='a' && ch<='z') {
        fputc('a'+25-ch+'a', stdout);
    } else {
        fputc(ch, stdout);
    } 
  }
  return 0;
}