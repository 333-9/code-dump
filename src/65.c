// 6 kyu
// Are they the "same"?


#include <stdbool.h>
#include <stdlib.h>

bool
comp(const int *a, const int *b, size_t n)
{
	int ai, bi;
	int *c = calloc(sizeof(int), n); /* "used" elements in *b */
	for (ai = 0; ai < n; ai++) {
		for (bi = 0; bi < n; bi++) {
			if (!c[bi] && a[ai] * a[ai] == b[bi]) {
				c[bi] = 1;
				goto Found;
			};
		};
		free(c);
		return false;
	Found:
		continue;
	};
	free(c);
	return true;
}
