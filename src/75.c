// 6 kyu
// Base Conversion


#include <string.h>

#define C_MAX 65
char *convert__itos(long int value, const char *source);
long int convert__stoi(const char *in, const char *source);


char *
convert(const char *in, const char *source, const char *target)
{
	return (convert__itos(convert__stoi(in, source), target));
};

long int
convert__stoi(const char *in, const char *source)
{ // string to long int
	const char *p = in, *d = source;
	long int out = 0, b = strlen(source), c = 1, i;
	for (; *p != '\0'; p++)
		;
	p--;
	for (; p + 1 != in; p--) {
		i = 0;
		for (; *d != *p; d++)
			i++;
		d = source;
		out += (i)*c;
		c *= b;
	};
	//printf("%i\n", c);
	return (out);
}


char *
convert__itos(long int value, const char *source)
{ // int to string
	if (!value) {
		char *out = calloc('\0', 2);
		*out = *source;
		return out;
	};
	char *out = malloc(C_MAX), *p = out;
	int b = strlen(source);
	for (int i = 0; i < C_MAX; i++)
		p++;
	*p = '\0';
	for (;;) {
		if (!value)
			break;
		p--;
		*p = *(source + (value % b));
		//printf("%i\n", value);
		value = (value - (value % b)) / b;
	};
	void *pt = out;
	out = malloc(strlen(p));
	strcpy(out, p);
	free(pt);
	return (out);
}
