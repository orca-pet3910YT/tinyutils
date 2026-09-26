#include <stdio.h>

int main(int argc, char *argv[]) {
	if (!argc) {
		puts("\n\n"); return 0;
	}
	for (int i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	putc('\n', stdout);
	return 0;
}
