// 6 kyu
// Playing with digits


#include <stdlib.h>
#include <stdio.h>

long
pow(long a, int n)
{
	return n ? a * pow(a, n - 1) : 1;
}

int
digPow(int n, int p)
{
	char ibuf[12];
	long l = 0;
	sprintf(ibuf, "%d", n);
	for (int i = 0; ibuf[i]; i++)
		l += pow(ibuf[i] - '0', p + i);
	return (l % n) ? -1 : l / n;
}
