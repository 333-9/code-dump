// 7 kyu
// By 3, or not by 3? That is the question . . . #3


#include <stdbool.h>

bool
divisible_by_three(const char *s)
{
	int n = 0;
	for (; *s != '\0'; s++)
		n += *s - '0';
	return (!(n % 3));
}
