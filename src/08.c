// 7 kyu
// Alternate capitalization


#include <stdlib.h>
#include <string.h>

char **
capitalize(char *s)
{
	char **o = malloc(2 * sizeof(char *));
	o[0] = strdup(s);
	o[1] = strdup(s);
	for (int i = 0; s[i]; i++)
		o[i & 1][i] -= 0x20;
	return o;
}
