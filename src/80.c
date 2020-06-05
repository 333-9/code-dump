// 7 kyu
// Shortest Word


#include <sys/types.h>
#include <string.h>

ssize_t
find_short(const char *s)
{
	char i = -1, max = 100;
	for (; *s != '\0'; s++) {
		i++;
		if (*s == ' ') {
			if (i < max)
				max = i;
			i = -1;
		};
	};
	if (i++ < max)
		max = i;
	return (max);
};
