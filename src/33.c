// 6 kyu
// Sum of Digits / Digital Root


int
digital_root(int n)
{
	int r = 0;
	while (n) {
		r += n % 10;
		n /= 10;
	};
	return (r >= 10 ? digital_root(r) : r);
}
