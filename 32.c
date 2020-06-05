// 4 kyu
// Range Extraction


#include <stdlib.h>
#include <stdio.h>

char *
range_extraction(const int *arr, size_t sz)
{
	int i, *p = NULL;
	char *str = calloc(0x400, 1);
	for (i = 0; i < (sz - 1); i++) {
		if (arr[i] + 1 == arr[i + 1]) {
			if (!p)
				p = arr + i;
		} else {
			if (p)
				sprintf(str, "%s%i%c%i,", str, *p,
				        ((*p + 1 == arr[i]) ? ',' : '-'),
				        arr[i]);
			else
				sprintf(str, "%s%i,", str, arr[i]);
			p = NULL;
		};
	};
	if (p)
		sprintf(str, "%s%i%c%i", str, *p,
		        ((*p + 1 == arr[i]) ? ',' : '-'), arr[i]);
	else
		sprintf(str, "%s%i", str, arr[i]);
	return str;
}
