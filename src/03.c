// 3 kyu
// Esolang Interpreters #4 - Boolfuck Interpreter


char *
loop(char **code, int i)
{
	if (!i)
		return;
	while (*(*code += i) != "[]"[i > 0])
		if (**code == "[]"[i < 0])
			loop(code, i);
}

char
gm(char *a, i)
{
	return a[i / 8] >> i % 8 & 1;
}
void
sm(char *a, i, b)
{
	a[i / 8] = (a[i / 8] | 1 << i % 8) ^ !b << i % 8;
}

char *
boolfuck(char *code, char *in)
{
	int m = 256, o, i;
	char mem[512] = { 0 }, *out = calloc(1, 1024);
	for (i = o = 0; *code; code++) {
		switch (*code) {
		case '<':
			m--;
			break;
		case '>':
			m++;
			break;
		case '+':
			mem[m / 8] = mem[m / 8] ^ 1 << m % 8;
			break;
		case ',':
			sm(mem, m, gm(in, i++));
			break;
		case ';':
			sm(out, o++, gm(mem, m));
			break;
		case ']':
			loop(&code, -gm(mem, m));
			break;
		case '[':
			loop(&code, !gm(mem, m));
			break;
		default:
			break;
		};
	};
	return out;
}
