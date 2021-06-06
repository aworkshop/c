#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define INT_MAX +2147483647
// count the chars from stdin and display table to stdout
int main(int argc, char**argv) {
  int len=256;
  long count[len];
  int ch;
  int i,j;
  for (i=0;i<len;i++) {
    count[i]=0;
  }
  while((ch=fgetc(stdin))!=-1) {
    count[ch]++;
  }
  int min=INT_MAX;
  int max;
  for (i=0;i<len;i++) {
    if (count[i]>0) max=i;
    if (min==INT_MAX && count[i]>0) min=i;
  }
  int x;
  for(j=0;j<len/8;j++){ // 32 lines
    if (j<min/8)
      continue;
    for (i=0;i<len/32;i++) { // 8 cols
      x=j*8+i;
      fprintf(stdout,"0x%02x %c %ld\t",x, isprint(x)?x:'.', count[x]);
    }
    fprintf(stdout,"\n");
    if (x>=max) 
      break;
  }
  return 0;
}
