// 6 kyu
// Tribonacci Sequence


#include <stdlib.h>

long long *
tribonacci(const long long signature[3], size_t n)
{
	if (signature == NULL || n == 0)
		return (NULL);
	long long *ret = malloc(sizeof(long long) * n), *p;
	p = ret;
	for (int i = 0; i < 3 && i < n; i++) {
		*p = signature[i];
		p++;
	};
	if (n > 3)
		n -= 4;
	else
		return (ret);
	for (; n; n--) {
		*p = *(p - 3) + *(p - 2) + *(p - 1);
		p++;
	};
	*p = *(p - 3) + *(p - 2) + *(p - 1);
	return (ret);
};
