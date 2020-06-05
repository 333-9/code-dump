// beta
// My smallest code interpreter (aka Brainf**k)


#include <stdlib.h>

char *
loop(char *code, signed char d)
{
	for (code += d; *code != (d == 1 ? ']' : '['); code += d)
		if (*code == (d == 1 ? '[' : ']'))
			code = loop(code, d);
	return code;
}

char *
brain_luck(char *code, char *in)
{
	char *result = malloc(0x159), *rp = result;
	char *mem = calloc(1, 0xff), *p = mem;
	for (; *code; code++) {
		switch (*code) {
		case '<':
			p--;
			break;
		case '>':
			p++;
			break;
		case '+':
			(*p)++;
			break;
		case '-':
			(*p)--;
			break;
		case '.':
			*rp++ = *p;
			break;
		case ',':
			*p = *in++;
			break;
		case ']':
			code = *p ? loop(code, -1) : code;
			break;
		case '[':
			code = *p ? code : loop(code, 1);
			break;
		};
	};
	*rp = '\0';
	free(mem);
	return result;
}
