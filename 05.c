// 6 kyu
// Find The Parity Outlier


#include <stdlib.h>

int
find_outlier(const int *a, size_t sz)
{
	if (abs(*a) % 2 != (abs(a[1]) % 2 & abs(a[2]) % 2))
		return *a;
	while (sz--)
		if (abs(*a) % 2 ^ abs(*++a) % 2)
			return *a;
}
