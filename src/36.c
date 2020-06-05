// 4 kyu
// Human readable duration format #3


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
get_num_comp(int *i, int m)
{
	int ret;
	ret = *i % m;
	*i /= m;
	return (ret);
}

void
cat_next(char *s, int *sum, int *prev, int i, const char *name)
{
	char *temp = malloc(10);
	*sum -= i;
	if (*prev && *sum)
		strcat(s, ", ");
	else if (*prev)
		strcat(s, " and ");
	*prev += 1;
	sprintf(temp, "%i %s", i, name);
	strcat(s, temp);
	if (i > 1)
		strcat(s, "s");
	free(temp);
}

char *
formatDuration(int t)
{
	char *ret = malloc(64);
	int sec, min, hour, day, year, sum;
	*ret = '\0';
	if (t == 0) {
		strcat(ret, "now");
		return (ret);
	};
	sec = get_num_comp(&t, 60);
	min = get_num_comp(&t, 60);
	hour = get_num_comp(&t, 24);
	day = get_num_comp(&t, 365);
	year = t;
	sum = sec + min + hour + day;
	if (year) {
		sprintf(ret, "%i %s", year, "year");
		if (year > 1)
			strcat(ret, "s");
	};
	if (day)
		cat_next(ret, &sum, &year, day, "day");
	if (hour)
		cat_next(ret, &sum, &year, hour, "hour");
	if (min)
		cat_next(ret, &sum, &year, min, "minute");
	if (sec)
		cat_next(ret, &sum, &year, sec, "second");
	return (ret);
}
