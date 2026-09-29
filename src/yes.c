#include <stdio.h>

int main(int argc, char *argv[]) {
	for (;;) {
		puts(argc > 1 ? argv[1] : "y");
	}
}
