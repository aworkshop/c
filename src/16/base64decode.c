#include <stdio.h>
#include <stdlib.h>
/* Base64 decoder - trial-and-error version.
 */

int get6bits(int ch) {
  // decode
  int bits=0;
  int base = 0;
  if (ch>='A' && ch<='Z') {
    //A-Z 000000 011010 (26)
    bits = (ch-'A');
    base=0;
  } else if (ch>='a' && ch<='z') {
    //a-z
    bits = (ch-'a');
    base = 26;
  } else if (ch>='0' && ch<='9') {
    //0-9
    bits = (ch-'0');
    base = 52;                   
  } else if (ch=='+'|| ch=='-') {
    // -
    bits =0;
    base = 62;
  } else if (ch=='/' || ch=='_') {
    // _
    bits=0;
    base = 63;
  } else {
    // = padding
    if (ch!='=')
      fprintf(stderr,"ERROR: %c 0x%0x to decode.\n",ch,ch);
    bits=0;
    base=0;
  }
  return (bits + base) & 0x3f;
}


int main(int argc, char**argv){

  if (argc==1) {
    int ch1;
    long collect=0;
    int bitcount=0;
    while((ch1=fgetc(stdin))!=-1) {
      // skip CRLF in the input
      if(ch1==0x0a ||ch1==0x0d)
        continue;
      // shift left 6; make space for the next 6 bits
      collect <<=6;
      if (ch1!='=') {
        collect |= get6bits(ch1);
        bitcount +=6;
      }
      
      // write out when there is info
      if (ch1=='=' && bitcount==8) {
        break;
      }
      if (bitcount>=8) {
        int ou = collect>>(bitcount-8)&0xff;
        fputc(ou,stdout);
        bitcount-=8;
        // we use the bitcount, so no need to clear collect bits
      }
      
    }
  }
  return 0;
}
