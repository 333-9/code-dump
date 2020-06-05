// 6 kyu
// Arrays, take n elements


int *
ary_take(int *a, long s, long n, long *r)
{
	return (*r = n ? n < s ? n : s : 0) ?
	               memcpy(malloc(*r * 4), a, *r * 4) :
	               0;
}


#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int *
ary_take(const int *arr, size_t sz, size_t n, size_t *rsz)
{
	if (n == 0)
		*rsz = 0;
	else if (n < sz)
		*rsz = n;
	else
		*rsz = sz;
	return *rsz ? memcpy(malloc(*rsz << 2), arr, *rsz << 2) : NULL;
}
