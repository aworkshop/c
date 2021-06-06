#include <stdio.h>
#include <string.h>
int main(int argc, char*argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1],"secret") == 0) {
            printf("flag{hi}");
        }
    }
    return 0;
}
