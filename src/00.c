// 6 kyu
// A String of Sorts


#include <stdlib.h>
#include <string.h>

const char *g = NULL;

int
get_order(const char *a, const char *b)
{
	size_t ao = (ao = strchr(g, *a)) ? 1 + ao - (long)g : 0;
	size_t bo = (bo = strchr(g, *b)) ? 1 + bo - (long)g : 0;
	return (ao * bo) ? ao - bo : ao ? -ao : bo;
}

char *
sort_string(char *string, const char *ordering)
{
	string = strdup(string);
	g = ordering;
	qsort(string, strlen(string), 1, &get_order);
	return string;
}
