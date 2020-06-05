// 4 kyu
// Snail


#include <stdlib.h>

int *
snail(size_t *outsz, const int **mx, size_t a, size_t b)
{
	int *p, *out, i, o = 1;
	*outsz = a * a;
	if (a == 0)
		return NULL;
	p = out = malloc(*outsz << 2);
	*p++ = **mx;
	while (a-- > 1) {
		for (b = a, i = o; b--; i++)
			*p++ = mx[o - 1][i];
		for (b = a, i = o; b--; i++)
			*p++ = mx[i][a + o - 1];
		*p++ = mx[a + o - 1][a + o - 2];
		if (a-- < 1)
			break;
		for (b = a, i = a + o - 2; b--; i--)
			*p++ = mx[a + o][i];
		for (b = a, i = a + o - 1; b--; i--)
			*p++ = mx[i][o - 1];
		*p++ = mx[o][o++];
	};
	return out;
}
