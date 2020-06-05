// 6 kyu
// Replace With Alphabet Position


char *
alphabet_position(char *text)
{
	char *buf = malloc(3 * strlen(text)), *p = buf;
	;
	if (!p)
		return calloc(1, 1);
	for (; *text; text++)
		if (isalpha(*text))
			buf += sprintf(buf, "%d ", (*text | 040) - '`');
	buf[-(p != buf)] = 0;
	return p;
}
