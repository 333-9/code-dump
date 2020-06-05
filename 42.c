// 8 kyu
// Grasshopper - Summation


int
summation(int n)
{
	return (n + (n == 1 ? 0 : summation(n - 1)));
}
