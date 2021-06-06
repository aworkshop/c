#include <stdio.h>
#include <stdlib.h>
int main(int argc, char**argv){
  if(argc<4){
    printf("Usage: %s <file> <offset> <byte> ...\n",argv[0]);
    exit(1);
  }
  FILE *f=fopen(argv[1],"r+");
  fseek(f,strtol(argv[2],NULL,16),SEEK_SET);
  int i=3;
  do{
    fputc(strtol(argv[i],NULL,16),f);
    i++;
  } while(i<argc);
  fclose(f);
  return 0;
}

// compile and run the patch
// gcc patch.c -o patch
// ./patch file 0x1168 0xeb 0x39
