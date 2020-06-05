// 6 kyu
// Generic numeric template formatter


#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

char *
numeric_formatter(const char *template, const char *input)
{
	int i, j;
	char *buf;
	if (*input == '\0')
		input = "1234567890";
	buf = strdup(template);
	for (i = j = 0; buf[i] != '\0'; i++) {
		if (isalpha(buf[i])) {
			if (input[j] == 0)
				j = 0;
			buf[i] = input[j++];
		};
	};
	return buf;
}
