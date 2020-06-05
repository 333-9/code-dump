// 6 kyu
// Duplicate Encoder


#define INDEX(c) (c > 'z' ? c - 26 : (c >= 'a' ? c - 32 : c)) - ' ' + 1

char *
DuplicateEncoder(char *s)
{
	char *p, *result, size = 0, dup[100] = { 0 };
	for (p = s; *p; p++, size++)
		dup[INDEX(*p)]++;
	result = malloc(size + 1);
	for (p = s, size = 0; *p; p++, size++)
		result[size] = dup[INDEX(*p)] > 1 ? ')' : '(';
	result[size] = '\0';
	return (result);
}
