#include <stdio.h>
#include <ctype.h>

// LEN nr of bytes per line
#define LEN 16
// Expression for 0..15 to '0'..'f'
#define HEX(i) ((i)<0xa?(i)+'0':(i)-0xa+'a')

unsigned char inp[LEN+1]; // input

// per byte: 2 hex chars + space + printable, 2*|
char line[LEN*4+2]; // output line

/**
 * param ch the char
 * param hex the address to write the 2 hex chars
 */
void hexch(unsigned char ch, char*hex) {
  int high = (ch & 0xf0) >> 4;
  int low  = (ch & 0x0f);
  hex[0]=HEX(high);
  hex[1]=HEX(low);
}

/**
 * param inp = the input
 * param n = nr of chars in the input
 * param line = output line
 */
void hexline(unsigned char*inp, int n, char *line) {
  // hex and printables on the line
  for (int i=0;i<n;i++) {
    hexch(inp[i], &line[i*3]);
    line[i*3+2]=' ';
    line[LEN*3+1+i] = isprint(inp[i])?inp[i]:'.';
  }
  // spaces on the line
  for (int i=n;i<LEN;i++) {
    line[i*3  ]=' ';
    line[i*3+1]=' ';
    line[i*3+2]=' ';
    line[LEN*3+1+i] = ' ';
  }
  // separators
  line[LEN*3]='|';
  line[LEN*4+1]='|';
}

int main() {
  line[LEN] = '\0';
  long address = 0;
  int n;
  while (n = fread(inp, sizeof(char), LEN, stdin), n>0) {
    hexline(inp, n, line);
    printf("%08lx: %s\n",address, line);
    address+=n;
  }
  printf("\n");
}
