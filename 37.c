// 5 kyu
// RGB To Hex Conversion


int hex(a)
{
	return (a < 0 ? 0 : (a > 0xff ? 0xff : a));
}

void
rgb(int r, g, b, char *buf)
{
	sprintf(buf, "%02X%02X%02X", hex(r), hex(g), hex(b));
}


void
rgb(int r, int g, int b, char *output)
{
#define B_round(n) n<0 ? 0 : n> 255 ? 255 : n
	sprintf(output, "%02X%02X%02X", B_round(r), B_round(g), B_round(b));
}
