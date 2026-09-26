#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int main() {
	int uid = getuid();
	struct passwd *uname = getpwuid(uid);
	int gid = getgid();
	struct group *gstruct = getgrgid(gid);
	printf("uid=%d(%s) gid=%d(%s)\n", uid, uname->pw_name, getgid(), gstruct->gr_name);
	return 0;
}
