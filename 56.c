// 7 kyu
// By 3, or not by 3? That is the question . . .


char
divisible_by_three(const char *s)
{
	short i = 0;
	while (*s)
		i += *s++ - '0';
	return !(i % 3);
}
