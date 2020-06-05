// 5 kyu
// Greed is Good


int
score(const int dice[5])
{
	int sides[6] = { 0 }, i, points = 0;
	for (i = 0; i < 5; i++) {
		sides[dice[i] - 1]++;
	};
	for (i = 1; i < 6; i++) {
		if (sides[i] >= 3)
			points += (i + 1) * 100;
	};
	points += (sides[0] >= 3) ? 1000 : 0;
	points += (sides[0] % 3) * 100;
	points += (sides[4] % 3) * 50;
	return (points);
}
