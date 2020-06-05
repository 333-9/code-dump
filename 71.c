// 5 kyu
// Double Cola


#include <stddef.h>

const char *
who_is_next(long long n, size_t len, const char *const *a)
{
	if (!n)
		return NULL;
	long int *m = malloc(len * sizeof(long int)), p = 0;
	for (int i = 0; i < len; i++)
		*(m + i) = 1;
	for (; n > 0; p++) {
		if (p >= len)
			p = 0;
		n -= *(m + p);
		*(m + p) *= 2;
	};
	free(m);
	return (*(a + p - 1));
}
