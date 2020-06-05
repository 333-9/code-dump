// 6 kyu
// Triangle type


//  0 : err
//  1 : acute
//  2 : right
//  3 : obtuse
int
triangleType(int a, int b, int c)
{
	int temp;
	if (c < a) {
		temp = c;
		c = a;
		a = temp;
	};
	if (c < b) {
		temp = c;
		c = b;
		b = temp;
	};
	temp = a * a + b * b;
	if ((a + b) <= c)
		return 0;
	else if (c * c > temp)
		return 3;
	else if (c * c < temp)
		return 1;
	else
		return 2;
}
