// 4 kyu
// Multiplying numbers as strings


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *
alloc(size_t size)
{
	static void *p = NULL;
	if (p != NULL)
		free(p);
	p = calloc(1, size);
	return p;
}

//char result[255];
char *
multiply(char *a, char *b)
{
	char *result = alloc(strlen(a) + strlen(b) + 200), *p, *end = b;
	for (; *a == '0'; a++)
		;
	for (; *b == '0'; b++)
		;
	if (!*a || !*b) {
		result[0] = '0';
		result[1] = '\0';
		return (result);
	};
	int cur, dig, mut, i, len, bi;
	for (; *end; end++)
		;
	end--;
	len = strlen(b) + strlen(a);
	/**/
	for (; *a != '\0'; a++) {
		mut = *a - 0x30;
		dig = 0;
		i = len;
		result[i] = 0;
		if (!mut)
			goto end;
		for (p = end; p >= b; p--) {
			dig += ((*p - 0x30) * mut);
		loop:
			i--;
			dig += result[i];
			result[i] = dig % 10;
			dig /= 10;
		};
		if (dig)
			goto loop;
	end:
		len++;
	};
	while (!result[0]) {
		for (i = 1; i < len; i++)
			result[i - 1] = result[i];
		len--;
	};
	for (i = 0; i < len - 1; i++)
		result[i] += 0x30;
	return (result);
}
