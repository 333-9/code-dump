// 5 kyu
// Scramblies


#include <stdbool.h>

bool
scramble(const char *str1, const char *str2)
{
	short int l[26] = { 0 };
	for (; *str1 != '\0'; str1++)
		l[*str1 - 0x61]++;
	for (; *str2 != '\0'; str2++)
		if (!(l[*str2 - 0x61]--))
			return (false);
	return (true);
};
