// 6 kyu
// Bouncing Balls


int
bouncingBall(double h, double b, double h2)
{
	int i;
	if (h <= 0.0 || b >= 1.0 || b <= 0.0 || h2 >= h)
		return -1;
	for (i = 0; h2 < h; i += 1 + (h2 < (h *= b)))
		;
	return i;
}
