// 5 kyu
// Conway's Look and Say - Generalized


#include <stdio.h>
#include <stdlib.h>

unsigned long long
look_say(unsigned long long n)
{
	if (n == 0)
		return 10;
	unsigned long long t = 0;
	int d, i = 1, lz = ((d = n % 10) == 0) ? 1 : 0;
	for (; (n /= 10) != 0;) {
		if ((n % 10) == d) {
			i++;
		} else {
		add_digit:
			t = (t * 10) + d;
			for (; i != 0; i /= 10)
				t = (t * 10) + (i % 10);
			d = n % 10;
			i = 1;
		};
	};
	if (d != 0)
		goto add_digit;
	for (n = 0; t != 0; t /= 10)
		n = (n * 10) + (t % 10);
	if (lz)
		n *= 10;
	return n;
}
