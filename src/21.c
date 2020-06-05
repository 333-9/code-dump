// 6 kyu
// Counting Duplicates


#include <stddef.h>

size_t
duplicate_count(const char *str)
{
	int i, count;
	char tab[36] = { 0 };
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] < 'A')
			tab[str[i] - '0']++;
		else if (str[i] < 'a')
			tab[10 + str[i] - 'A']++;
		else
			tab[10 + str[i] - 'a']++;
	};
	for (count = i = 0; i < 36; i++) {
		if (tab[i] >= 2)
			count++;
	};
	return count;
}
