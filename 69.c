// 4 kyu
// Count ones in a segment


long long
count(int n)
{
	long long result = 0;
	int i = 1, r = 1, lsb;
	while (n) {
		lsb = n & 1;
		result += r * lsb;
		r += i * lsb;
		n >>= 1;
		result += n * i;
		i *= 2;
	};
	return (result);
}

int
count_b(int n)
{
	int result = 0;
	for (; n; n >>= 1) {
		result += n & 1;
	};
	return (result);
}

long long
countOnes(int left, int right)
{
	return (count(right) - count(left) + count_b(left));
}
