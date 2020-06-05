// 5 kyu
// Strings: implement your own "strtok" function!


#include <string.h>

char *
my_strtok(char *src, const char *delims)
{
	static char *p = NULL;
	if (src != NULL)
		p = src;
	else if (p == NULL)
		return NULL;
	else
		src = p;
	for (; index(delims, *p) != NULL; p++)
		if (*p == '\0')
			return NULL;
	for (src = p; index(delims, *p) == NULL; p++)
		;
	if (*p == '\0')
		p = NULL;
	else
		*(p++) = '\0';
	return src;
}
