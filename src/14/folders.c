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
    case DT_DIR: t = '/'; break; // directory
    case DT_BLK: t = 'B'; break;
    case DT_REG: t = ' '; break; // regular file
    case DT_LNK: t = '>'; break; // link
    case DT_SOCK: t = 'S'; break;
    case DT_WHT: t = 'W'; break;
    default:  t = '?'; break;
  }
  return t;
}

DIR *dir;
struct dirent *entry;

int main(int argc, char *argv[]) {

  if (argc==1)
    dir = opendir(".");
  else if (argc==2)
    dir = opendir(argv[1]);
  else
    exit(1);
  //
  while((entry = readdir(dir))!=NULL) {
    printf("%s %c\n", entry->d_name, dtype(entry) );
  }
  closedir(dir);
}
