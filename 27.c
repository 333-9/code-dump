// 4 kyu
// Shortest Knight Path #2


short
knight(const char *cur, const char *dest)
{
	int a, b;
	a = abs(cur[0] - dest[0]);
	b = abs(cur[1] - dest[1]);
	return ("032214323223234343434434345454545456"[a > b ? a * ++a / 2 + b :
	                                                       b * ++b / 2 + a] -
	        '0');
}
