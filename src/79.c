// 6 kyu
// Roman Numerals Encoder


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char RN_S[16];


// copy digits from src to dest
void
rn_chcpy(char n1, char n2, char src[2], char **dest)
{
	if (n1 == 9) {
		char t = **dest;
		**dest = src[0];
		(*dest)++;
		**dest = t;
		n1 = 0;
		n2 = 0;
		(*dest)++;
	} else if (n1 == 5) {
		**dest = src[1];
		n1 = 0;
		(*dest)++;
	} else if (n1 == 4) {
		**dest = src[0];
		(*dest)++;
		**dest = src[1];
		n1 = 0;
		(*dest)++;
	} else if (n2) {
		**dest = src[1];
		n1 -= 5;
		(*dest)++;
	};
	for (; n1; n1--) {
		**dest = src[0];
		(*dest)++;
	};
	**dest = src[0];
};

char *
solution(int n)
{
	char ret[16] = { '\0' }, *p = NULL;
	char m = (n - (n % 1000)) / 1000, c = ((n % 1000) - (n % 100)) / 100,
	     x = ((n % 100) - (n % 10)) / 10, i = (n % 10);
	char d = 0, l = 0, v = 0;
	c<10 && c> 3 ? (d = 1) : (c %= 5);
	x<10 && x> 3 ? (l = 1) : (x %= 5);
	i<10 && i> 3 ? (v = 1) : (i %= 5);
	//printf("%i, %i, %i, %i\n", m, c, x, i);
	//printf("%i, %i, %i\n", d, l, v);
	p = ret;
	rn_chcpy(m, 0, "M ", &p);
	rn_chcpy(c, d, "CD", &p);
	rn_chcpy(x, l, "XL", &p);
	rn_chcpy(i, v, "IV", &p);
	*p = '\0';
	strncpy(RN_S, ret, 16);
	return (RN_S);
};
