// 6 kyu
// Separate The Wheat From The Chaff


long *
wheat_from_chaff(const long *arr, int b)
{
	int a = 0;
	long *out = malloc(sizeof(long) * b);
	do {
		if (arr[a] < 0) {
			out[a] = arr[a];
		} else {
			for (b--; b > a && arr[b] > 0; b--)
				out[b] = arr[b];
			out[b] = arr[a];
			out[a] = arr[b];
		};
	} while (++a <= b - 1);
	return out;
}


long long *
wheat_from_chaff(const long long *val, unsigned count)
{
	int i = 0;
	long long *val2 = malloc(sizeof(long long) * count);
	count--;
	for (; i <= count; i++) {
		val2[i] = val[i];
		if (val[i] < 0) {
			continue;
		};
		for (; count > i; count--) {
			val2[count] = val[count];
			if (val[count] > 0) {
				continue;
			};
			val2[count] = val[i];
			val2[i] = val[count];
			count--;
			break;
		};
	};
	return (val2);
}
