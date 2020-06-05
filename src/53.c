// 8 kyu
// Is n divisible by x and y?


char
isDivisible(const int n, const int x, const int y)
{
	return !((n % x) || (n % y));
}
