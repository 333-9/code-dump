// 4 kyu
// Human readable duration format #2


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *words[5] = { "second", "minute", "hour", "day", "year" };
int count[4] = { 60, 60, 24, 365 };

char *
sep(int *arr, int i)
{
	int n = 0;
	while (i--)
		if (arr[i])
			n++;
	return n ? (n < 2 ? " and " : ", ") : "";
}

char *
formatDuration(int n)
{
	char *buf = calloc(64, 1);
	int i, arr[5] = { 0 };
	if (!n)
		return strcat(buf, "now");
	for (i = 0; i < 4; i++) {
		arr[i] = n % count[i];
		n /= count[i];
	};
	arr[i++] = n;
	while (i--)
		if (arr[i])
			sprintf(buf, "%s%d %s%s%s", buf, arr[i], words[i],
			        (arr[i] != 1 ? "s" : ""), sep(arr, i));
	return buf;
}
