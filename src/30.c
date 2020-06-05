// 5 kyu
// Write your own printf


#include <stdarg.h>
#include <stdlib.h>

char *
mr_asprintf(const char *format, ...)
{
	va_list arg;
	char *p, *buf = calloc(0x400, 1);
	va_start(arg, format);
	for (;;) {
		if (!(p = strchr(format, '{'))) {
			strcat(buf, format);
			break;
		};
		strncat(buf, format, p - (size_t)format);
		format = ++p;
		switch (*format++) {
		case '{':
			strcat(buf, "{");
			break;
		case 'i':
			sprintf(buf, "%s%i", buf, va_arg(arg, int));
			format++;
			break;
		case 's':
			strcat(buf, va_arg(arg, char *));
			format++;
			break;
		};
	};
	va_end(arg);
	return buf;
}
