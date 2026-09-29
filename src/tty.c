#include <stdio.h>
#include <unistd.h>

int main() {
	printf("%s\n", ttyname(STDIN_FILENO));
}
