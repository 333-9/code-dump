// 5 kyu
// Maximum subarray sum


#include <stddef.h>

int
maxSequence(const int *array, size_t n)
{
	if (!n)
		return 0;
	int max = 0;
	for (int w = 1; w != n; w++) {
		for (int o = 0; o < n - w; o++) {
			int sum = 0;
			for (int p = 0; p < w; p++)
				sum += array[p + o];
			if (sum > max)
				max = sum;
		};
	};
	return max;
}
