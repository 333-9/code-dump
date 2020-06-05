// 4 kyu
// Shortest Knight Path


/* my first solution did not check for all corner cases */

int
corner(char *p)
{
	return !((*p ^ 97 && *p ^ 104) || (*++p ^ 49 && *p ^ 56));
}

int
knight(char *s, char *e)
{
	int a = abs(*s++ - *e++), b = abs(*s - *e);
	return !(a * b ^ 1) && corner(--s) ^ corner(--e) ?
	               4 :
	               "032214323223234343434434345454545456"
	                               [a + b + (a > b ? b + a * a : a + b * b) >>
	                                1] -
	                       48;
}
