#include <stdio.h>
#include <time.h>

int main() {
	time_t time_converted = time(NULL);
	printf("%s", ctime(&time_converted));
	return 0;
}
