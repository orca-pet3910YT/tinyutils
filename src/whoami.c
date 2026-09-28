#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main() {
	printf("%s\n", getpwuid(geteuid())->pw_name);
	return 0;
}
