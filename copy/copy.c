#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void usage(char *cmd) {
  printf("usage: %s <source filename> <destination filename>\n", cmd);
}

void failed(char *path) { printf("Failed to open file : %s\n", path); }

int main(int argc, char *argv[]) {
  int fd_src, fd_dst;

  if (argc != 3) {
    usage(argv[0]);
    return -1;
  }

  if ((fd_src = open(argv[1], O_RDONLY)) != -1) {
    int cnt = 0;
    char *buf = malloc(4096);
    if ((fd_dst = creat(argv[2], 0644)) != -1) {
      do {
        cnt = 0;
        cnt = read(fd_src, buf, 4096);
        if (cnt == write(fd_dst, buf, cnt)) {
          continue;
        }
      } while (cnt != 0);
      free(buf);
      close(fd_dst);
    } else {
      failed(argv[2]);
      close(fd_src);
      usage(argv[0]);
    }
  } else {
    failed(argv[1]);
    usage(argv[0]);
  }
  return 0;
}
