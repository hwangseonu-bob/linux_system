#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void usage(char *cmd) {
	printf("usage: %s <filename>\n", cmd);
}

int main(int argc, char *args[]) {
	int fd;
	
	if (argc == 1) {
		usage(args[0]);
		return -1;
	}

	fd = open(args[1], O_RDONLY);
	if (fd == -1) {
		printf("Failed to open file : %s\n", args[1]);
		usage(args[0]);
	} else {
		printf("Success to open file : %s\n", args[1]);
	}
	close(fd);
}
