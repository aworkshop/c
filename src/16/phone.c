#include <stdio.h>
#include <stdlib.h>
/* 
 * Old phone decoding. When pressing a digit multiple times, then
 * the characters are formed. 2 gets A, 22 gets B 22 gets C. Then
 * 3 gets D etcetera. Not all chars are in the set. 
 * Sets with 7 or 9 are 4 long.
 * 0 and 1 are not used.
 */

int main(int argc, char**argv){
  char *e="  ADGJMPTW";
  //       0123456789
  
  if (argc==1) {
    int ch;
    int prev;
    int times=0;
    while((ch=fgetc(stdin))!=-1) {
      if (ch>='0' && ch<='9') {
        // decode
        if (times>0) {
          if ((times==3&&ch!='7'&&ch!='9') || (times==4&&(ch=='7'||ch=='9'))) {
            // reached end so flush
            // '7' has 4, others have 3
            fputc( e[prev-'0']+times-1,stdout);            
            times = 1;
            prev = ch;
          } else if (ch!=prev) {
            // different, so flush 
            fputc( e[prev-'0']+times-1,stdout);                        
            times = 1;
            prev=ch;
          } else {
            // still the same
            times++;
          }
        } else {
          // times==0; so first digit
          prev=ch;
          times=1;
        }
      } else {
        // non digit
        // flush
        if (times>0) {
          fputc( e[prev-'0']+times-1,stdout);           
        }
        // do not decode
        fputc(ch,stdout);
        times = 0;
        prev=ch;
      }
    }
    // last
    if (times>0) {
      fputc( e[prev-'0']+times-1,stdout);                  
    }

  } else {
    printf("Usage: %s \nUse stdin and stdout.\n",argv[0]);
  }

  return 0;
}
