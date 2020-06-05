// 6 kyu
// Counting Duplicates #2


#include <stddef.h>

size_t
duplicate_count(const char *text)
{
#define N_CHARS 26
	char map[N_CHARS + 10] = { 0 };
	int i, n;
	for (; *text; text++) {
		if (*text <= '9')
			map[(*text - '0') + N_CHARS]++;
		else if (*text <= 'Z')
			map[*text - 'A']++;
		else
			map[*text - 'a']++;
	};
	for (i = n = 0; i < (N_CHARS + 10); i++)
		if (map[i] > 1)
			n++;
	return n;
}
