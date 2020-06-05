// 6 kyu
// Persistent Bugger.


int
mul_digits(int n)
{
	if ((n / 10) < 1)
		return n;
	else
		return ((n % 10) * mul_digits(n / 10));
}

int
persistence(int n)
{
	if ((n / 10) < 1)
		return 0;
	else
		return (1 + persistence(mul_digits(n)));
}
