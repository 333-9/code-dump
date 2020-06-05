// 7 kyu
// Even and Odd !


#include <math.h>
typedef unsigned long long ull;

ull *
eval(ull n)
{
	ull *result = calloc(0, 2 * sizeof(ull));
	ull i = 1, e = 1, o = 1;
	for (int d = 19; d; d--) {
		i *= 10;
		if (((n % i) / (i / 10)) & 1) {
			*(result + 1) =
			        (*(result + 1)) + ((n % i) / (i / 10)) * o;
			o *= 10;
		} else {
			*result = (*result) + ((n % i) / (i / 10)) * e;
			e *= 10;
		};
		//printf("%i ", (int) (n%i)/(i/10));
		n -= n % i;
	};
	if (n)
		*(result + 1) = (*(result + 1)) + 1 * o;
	return result;
};
