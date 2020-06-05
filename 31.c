// 5 kyu
// Write your own printf #2


#include <stdarg.h>
#include <stdlib.h>

char *
mr_asprintf(const char *format, ...)
{
	size_t size = 0x400;
	char *str = malloc(size), nbuf[16], *nbufp;
	size_t i = 0;
	char *s;
	int n;
	va_list ap;
	va_start(ap, format);
	for (; *format != '\0'; format++) {
		if (*format == '{') {
			format++;
			if (*format == '{') {
				str[i] = *format;
				i++;
			} else if (*format == 's') {
				s = va_arg(ap, char *);
				for (; *s != '\0'; s++, i++)
					str[i] = *s;
				format++;
				continue;
			} else if (*format == 'i') {
				nbufp = nbuf;
				n = va_arg(ap, int);
				if (n < 0) {
					str[i] = '-';
					i++;
					n = abs(n);
				} else if (n == 0) {
					*nbufp = '0';
					nbufp++;
				};
				for (; n != 0; n /= 10, nbufp++)
					*nbufp = '0' + (n % 10);
				for (nbufp--; nbufp >= nbuf; nbufp--, i++)
					str[i] = *nbufp;
				format++;
				continue;
			};
		} else {
			str[i] = *format;
		};
		i++;
	};
	va_end(ap);
	str[i] = '\0';
	return (&(str[0]));
}
