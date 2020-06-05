// 4 kyu
// Adding Big Numbers


#include <stdlib.h>
#include <string.h>

char *
add(char *ap, char *bp)
{
	while (*ap == '0')
		ap++;
	if (strlen(ap) < strlen(bp))
		return add(bp, ap);
	int i, carry = 0;
	char *buf = calloc(strlen(ap) + 3, 1);
	char *b = bp + strlen(bp) - 1;
	char *a = ap + strlen(ap) - 1;
	for (i = strlen(ap); i >= 0; i--) {
		if (b >= bp)
			buf[i] += *b-- - '0';
		if (a >= ap)
			buf[i] += *a-- - '0';
		buf[i] += '0' + carry;
		if (buf[i] > '9')
			carry = 1, buf[i] -= 10;
		else
			carry = 0;
	};
	return buf[0] > '0' ? buf : memmove(buf, buf + 1, strlen(ap) + 2);
}
