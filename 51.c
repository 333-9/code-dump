// 8 kyu
// Correct the mistakes of the character recognition software


char *
correct(char *s)
{
	char *s_original = s;
	for (; *s; s++) {
		if (*s == '5')
			*s = 'S';
		else if (*s == '1')
			*s = 'I';
		else if (*s == '0')
			*s = 'O';
	};
	return s_original;
}
