#include <stdio.h>
#include <unistd.h>

int main() {
	long nproc = sysconf(_SC_NPROCESSORS_ONLN);
	printf("%ld\n", nproc);
	return 0;
}
