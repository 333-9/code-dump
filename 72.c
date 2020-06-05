// 6 kyu
// CamelCase Method


#include <stdlib.h>
#include <ctype.h>

char *
camel_case(const char *s)
{
	char *w = malloc(50), *p = w, u = 1;
	for (; *s != '\0'; s++) {
		if (*s == ' ')
			u = 1;
		else if (*s != ' ') {
			if (u) {
				*p = (*s) - 0x20;
				u = 0;
			} else
				*p = *s;
			p++;
		};
	};
	*p = '\0';
	return w;
}
