// 8 kyu
// Century From Year


int
centuryFromYear(int year)
{
	return (year / 100 + (year % 100 > 0));
}
