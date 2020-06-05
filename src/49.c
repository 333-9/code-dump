// beta
// My smallest code interpreter (aka Brainf**k) #2


#include <stdlib.h>

char *
brain_luck(char *code, char *input)
{
	char stack[300] = { 0 }, *result = malloc(64), *p = code;
	*result =
	        '\0'; /* 'result' must contain at least one character - '\0' */
	int b, i = 0, ri = 0;
	while (*p != '\0') {
		switch (*p) {
		case ',':
			if (input == NULL)
				goto end;
			else
				stack[i] = *input;
			if (*input == '\0')
				input = NULL;
			else
				input++;
			break;
		case '.':
			result[ri] = stack[i];
			ri++;
			result[ri] = '\0';
			break;
		case '<':
			if (!i)
				goto end;
			i--;
			break;
		case '>':
			i++;
			break;
		case '+':
			if (stack[i] < 255)
				stack[i] += 1;
			else
				stack[i] = 0;
			break;
		case '-':
			if (stack[i] > 0)
				stack[i] -= 1;
			else
				stack[i] = 255;
			break;
		case ']':
			if (stack[i] == 0)
				break;
			for (b = 0, p--; p != code; p--) {
				if (*p == ']')
					b++;
				else if (*p == '[') {
					if (b == 0)
						break;
					b--;
				};
			};
			break;
		case '[':
			if (stack[i] != 0)
				break;
			for (b = 0, p++; p != '\0'; p++) {
				if (*p == '[')
					b++;
				else if (*p == ']') {
					if (b == 0)
						break;
					b--;
				};
			};
			break;
		default:
			break;
		};
		p++;
	};
end:
	return result;
}
