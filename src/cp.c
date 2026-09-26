#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	char *src, *dest;
	if (argc == 3) {
		src = argv[1];
		dest = argv[2];
	} else {
		printf("%s: usage: %s source dest\n", argv[0], argv[0]);
		return 1;
	}
	int fd_src, fd_dest;
	char buf[4096];
	ssize_t nread;
	fd_src = open(src, O_RDONLY);
	if (fd_src < 0) {
		//printf("%s: failed to open source\n", argv[0]);
		perror(argv[0]);
		return 1;
	}
	fd_dest = open(dest, O_WRONLY | O_CREAT | O_EXCL, 0666);
	if (fd_dest < 0) {
		//printf("%s: failed to open dest\n", argv[0]);
		perror(argv[0]);
		return 1;
	}
	while (nread = read(fd_src, buf, sizeof(buf)), nread > 0) {
		char *out_ptr = buf;
		ssize_t nwrite;
		do {
			nwrite = write(fd_dest, out_ptr, nread);
			if (nwrite >= 0) {
				nread -= nwrite;
				out_ptr += nwrite;
			} else if (errno != EINTR) {
				perror(argv[0]);
				return 1;
			}
		} while (nread);
	}
	if (nread) {
		if (close(fd_dest) < 0) {
			perror(argv[0]);
			return 1;
		}
		close(fd_src);
	}
	return 0;
}
