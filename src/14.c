// 6 kyu
// Who likes it?


#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

char *
likes(size_t n, const char *names[])
{
	char *buf;
	switch (n) {
	case 0:
		return strdup("no one likes this");
	case 1:
		buf = malloc(12 + strlen(*names));
		sprintf(buf, "%s likes this", *names);
		return buf;
	case 2:
		buf = malloc(18 + strlen(names[0]) + strlen(names[1]));
		sprintf(buf, "%s and %s like this", names[0], names[1]);
		return buf;
	case 3:
		buf = malloc(22 + strlen(names[0]) + strlen(names[1]) +
		             strlen(names[2]));
		sprintf(buf, "%s, %s and %s like this", names[0], names[1],
		        names[2]);
		return buf;
	default:
		buf = malloc(40 + strlen(names[0]) + strlen(names[1]));
		sprintf(buf, "%s, %s and %d others like this", names[0],
		        names[1], n - 2);
		return buf;
	};
}
