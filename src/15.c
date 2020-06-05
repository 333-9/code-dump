// 5 kyu
// Weight for weight


#include <stdlib.h>
#include <string.h>

char *ret;

int
chr_sum_cmp(const int *ap, const int *bp)
{
	int sum = 0, a = *ap, b = *bp;
	for (; ret[a]; a++)
		sum += ret[a] - '0';
	for (; ret[b]; b++)
		sum -= ret[b] - '0';
	return sum ? sum : strcmp(ret + *ap, ret + *bp);
};

char *
orderWeight(const char *s)
{
	int *arr, i, j, sz;
	char f = 1, *p;
	if (!(sz = strlen(s)))
		return calloc(1, 1);
	ret = strdup(s);
	arr = malloc(sz * 2);
	for (i = j = 0; i < sz; i++)
		if (ret[i] == ' ')
			ret[i] = 0, f = 1;
		else if (f)
			arr[j++] = i, f = 0;
	qsort(arr, j, sizeof(int), chr_sum_cmp);
	for (p = ret, i = 0; i < j; i++, *p++ = ' ')
		while (s[arr[i]] && s[arr[i]] != ' ')
			*p++ = s[arr[i]++];
	p[-1] = 0;
	return ret;
}
