// 4 kyu
// parseInt() reloaded


#define WORD_END(c) (c == '\0' || c == ' ' || c == '-')
#define E_OR_Y(c, n) (c == 'e' ? n + 10 : n * 10)

long
word_to_int(char *s)
{
	short n = 0;
	switch (*s) {
	case 'e':
		s += 5;
		if (WORD_END(*s))
			return 8;
		else if (*s == 'n')
			return 11;
		else
			return E_OR_Y(*s, 8);
	case 'f':
		if (*(++s) == 'o')
			n = 4;
		else
			n = 5;
		s += 3;
		if (WORD_END(*s))
			return n;
		return E_OR_Y(*(++s), n);
	case 'n':
		s += 4;
		if (WORD_END(*s))
			return 9;
		else
			return E_OR_Y(*(++s), 9);
	case 'o':
		return 1;
	case 's':
		if (*(++s) == 'e') {
			s += 2;
			n = 7;
		} else
			n = 6;
		s += 2;
		if (WORD_END(*s))
			return n;
		else
			return E_OR_Y(*(++s), n);
	case 't':
		if (*(++s) == 'w')
			n = 2;
		else if (*s == 'e')
			return 10;
		else
			n = 3;
		s += 2;
		if (WORD_END(*s))
			return 2;
		s += 2;
		if (WORD_END(*s))
			return 3;
		else
			return E_OR_Y(*s, n);
	};
}

long
parse_int(const char *num)
{
	long n = 0, t = 0;
	if (*num == 'z')
		return 0;
top:
	t += word_to_int(num);
	for (num += 3; !WORD_END(*num); num++)
		;
	if (*num == '\0')
		return (n + t);
	else if (*(num++) == '-') {
		goto top;
	} else {
		if (*num == 'm')
			return 1000000;
		else if (*num == 'h') { /* hundered */
			n += t * 100;
			t = 0;
			num += 7;
			if (*num == '\0')
				return n;
			if (*(++num) == 'a')
				num += 4;
			if (*num == 't' && *(num + 2) == 'o')
				goto thousand;
			goto top;
		} else { /* thousand */
		thousand:
			n = (n + t) * 1000;
			t = 0;
			num += 8;
			if (*num == '\0')
				return n;
			else if (*(++num) == 'a')
				num += 4;
			goto top;
		};
	};
	return n;
}
