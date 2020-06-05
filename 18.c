// 5 kyu
// Rot13


#include <ctype.h>

char *
rot13(char *s)
{
	s = strdup(s);
	for (int i = 0; s[i]; i++)
		s[i] += ((s[i] | 0x20) <= 'm' ? 1 : -1) * !!isalpha(s[i]) * 13;
	return s;
}
