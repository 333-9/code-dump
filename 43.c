// 7 kyu
// Make a function that does arithmetic!


double
arithmetic(double a, double b, char *op)
{
	switch (*op) {
	case 'a' /*add*/:
		return (a + b);
	case 's' /*sub*/:
		return (a - b);
	case 'm' /*mul*/:
		return (a * b);
	case 'd' /*dev*/:
		return (a / b);
	};
}
