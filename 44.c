// 6 kyu
// Mexican Wave


void
wave(const char *y, char **target)
{
	short l = strlen(y), i, ti;
	for (i = ti = 0; i < l; i++) {
		if (y[i] != ' ') {
			strcpy(target[ti], y);
			target[ti++][i] -= 32;
		};
	};
}
