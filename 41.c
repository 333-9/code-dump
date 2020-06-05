// 6 kyu
// Rectangle into Squares


#include <stdlib.h>

/* If from the beginning: length == width return Data with sz = 0 */
struct Data {
	int *array;
	size_t sz;
};

struct Data *
sqSub(struct Data *d, int i, int l, int w)
{
	if ((i + 4) >= d->sz)
		d->array = realloc(d->array, sizeof(int) * (d->sz += 0x20));
	if (l == w) {
		d->array[i] = l;
		d->sz = ++i;
		return d;
	} else if (l < w) {
		w -= (d->array[i] = l);
	} else if (l > w) {
		l -= (d->array[i] = w);
	};
	return sqSub(d, ++i, l, w);
}

struct Data *
sqInRect(int l, int w)
{
	struct Data *d;
	d = malloc(sizeof(struct Data));
	if (l == w) {
		d->sz = 0;
		return d;
	};
	d->sz = 0x20;
	d->array = malloc(sizeof(int) * (d->sz));
	return sqSub(d, 0, l, w);
}


#define MAX_SZ 300

typedef struct Data {
	int *array;
	int sz; // array size
} Data;

Data *
sqInRect(int l, int w)
{
	Data *rt = malloc(sizeof(Data));
	rt->array = malloc(sizeof(int) * MAX_SZ);
	if (l == w)
		rt->sz = 0;
	else {
		int *p, t;
		p = rt->array;
		rt->sz = 0;
		for (;;) {
			if (l < w) {
				t = w;
				w = l;
				l = t;
			} else {
				if (w) {
					*p = w;
					rt->sz++;
					p++;
				};
				l = l - w;
				if (!l)
					break;
			};
		};
		realloc(rt->array, sizeof(int) * rt->sz);
	};
	return (rt);
}
