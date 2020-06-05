// 6 kyu
// Take a Ten Minute Walk


#include <stdbool.h>

bool
isValidWalk(const char *walk)
{
	short int i = 0, n = 0, w = 0;
	for (; *walk != '\0'; walk++) {
		switch (*walk) {
		case 'n':
			n++;
			break;
		case 's':
			n--;
			break;
		case 'w':
			w++;
			break;
		case 'e':
			w--;
			break;
		};
		if (++i > 10)
			break;
	};
	if (!n && !w && i == 10)
		return true;
	return false;
}
