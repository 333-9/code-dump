// 6 kyu
// Consonant value


int
solve(const char *str)
{
	int highest = 0, score = 0;
	for (; *str != '\0'; str++) {
		if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' ||
		    *str == 'u') {
			if (score > highest)
				highest = score;
			score = 0;
		} else {
			score += (*str - 'a') + 1;
		};
	};
	return (highest);
}
