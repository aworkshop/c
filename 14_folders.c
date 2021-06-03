#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// man dirent

char dtype(struct dirent *entry) {
  char t = ' ';
  switch (entry->d_type) {
    case DT_UNKNOWN: t = 'U'; break;
    case DT_FIFO: t = 'F'; break;
    case DT_CHR: t = 'C'; break;
    case DT_DIR: t = 'D'; break;
    case DT_BLK: t = 'B'; break;
    case DT_REG: t = 'R'; break;
    case DT_LNK: t = 'L'; break;
    case DT_SOCK: t = 'S'; break;
    case DT_WHT: t = 'W'; break;
    default:  t = '?'; break;
  }
  return t;
}

DIR *dir;
struct dirent *entry;
struct restrict st;

int main(void) {

  dir = opendir(".");
  while((entry = readdir(dir))!=NULL) {
    int s = stat(entry->d_name, &st);
    printf("%c;%s,%d\n", dtype(entry), entry->d_name, st->st_size);
  }
  closedir(dir);
}
