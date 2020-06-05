// 7 kyu
// Vowel Count


#include <stddef.h>


size_t
get_count(const char *s)
{
	size_t count = 0;
	while (*s)
		count += strchr("aeiou", *s++) ? 1 : 0;
	return count;
}
