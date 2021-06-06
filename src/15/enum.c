#include <stdio.h>

enum off_on {Off, On};
enum boolean {false, true}; // false 0, true 1
enum days {Mon, Tue, Wed, Thu, Fri, Sat, Sun};

// override ints 0..3 with our values
enum wind {East=90, West=270, North=0, South=180};

// use powers of 2
enum settings { //int has 32 bits
  PORT80 = 1,
  PORT443 = 2,
  PORT8080 = 4,
  PORT8000 = 8,
  PORT22 = 0x10
} ports;

int main(void){

  // 'or' the settings
  ports = PORT80 | PORT22 | PORT8080;
  // test for a specific setting
  if (ports&PORT80) {  // works >0
    printf("Port 80 is used.\n");
  }
  // test for a specific setting
  if ((PORT8080 & ports) == PORT8080) { // better ==
    printf("Port 8080 is used.\n");
  }
  // add setting
  ports |= PORT443;
  printf("Ports 0x%02x, size %ld.\n", ports, sizeof(ports));
  // clear setting
  ports &= ~PORT22;
  printf("Ports 0x%02x, size %ld.\n", ports, sizeof(ports));

  // can be used in switch
  enum off_on light = On;
  switch(light) {
    case On:
      printf("On\n");
      break;
    case Off:
      printf("Off\n");
      break;
  }
  printf("West is %d degrees.\n", West);
}
