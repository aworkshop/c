#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
      printf("Usage: %s <size> <filename>\n", argv[0]);
      exit(1);
    }
    long size = atol(argv[1]);
    char *name = argv[2];
    printf("Sizing %ld to %s.\n", size, name);

    FILE *fp; 
    fp = fopen(name, "w");
    fseek(fp, size-1, SEEK_CUR);
    fputc('\0', fp);
    fclose(fp);

    return 0;
}
