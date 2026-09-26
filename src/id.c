#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	struct passwd *uname;
	if (argc > 1) {
		uname = getpwnam(argv[1]);
	} else {
		uname = getpwuid(getuid());
	}
	if (!uname) uname = getpwuid(getuid());
	int groupno = 0;
	getgrouplist(uname->pw_name, uname->pw_gid, NULL, &groupno);
	gid_t *groups = malloc(groupno*sizeof(*groups));
	if (!groups) return 1;
	getgrouplist(uname->pw_name, uname->pw_gid, groups, &groupno);
	gid_t gid = uname->pw_gid;
	struct group *gstruct = getgrgid(gid);
	uid_t uid = uname->pw_uid;
	printf("uid=%u(%s) gid=%u(%s) groups=(", (unsigned)uid, uname->pw_name, (unsigned)gid, gstruct->gr_name);
	for (int i = 0; i < groupno; i++) {
		struct group *groupstruct = getgrgid(groups[i]);
		if (groupstruct) printf("%u(%s)", (unsigned)groups[i], groupstruct->gr_name);
		else printf("%u(\?\?\?)", (unsigned)groups[i]);
		if (i < groupno-1) putc(',', stdout);
	}
	puts(")");
	return 0;
}
