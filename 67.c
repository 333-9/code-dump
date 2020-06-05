// 4 kyu
// Next smaller number with the same digits


unsigned long long
next_smaller_number(unsigned long long n)
{
	char list[10] = { 0 }, max;
	int s = 0, prev = 9, i;
	while (n) {
		s = n % 10;
		n /= 10;
		if (s > prev) {
			for (i = s - 1; i > 0 || (i >= 0 && n); i--) {
				if (list[i]) {
					n *= 10;
					n += i;
					list[i]--;
					break;
				};
			};
			if (!n)
				return -1;
			list[s]++;
			for (i = 9; i >= 0; i--) {
				for (; list[i]; list[i]--) {
					n *= 10;
					n += i;
				};
			};
			return n;
		};
		prev = s;
		list[s]++;
	};
	return -1;
}
