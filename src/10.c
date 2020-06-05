// 4 kyu
// The observed PIN


#include <stdlib.h>

const char *tab[] = {
	"08",    "124",  "1235", "236",   "1457",
	"24568", "3569", "478",  "05789", "689",
};

const char **
get_pins(const char *observed, size_t *count)
{
	int i, j, carry, sz = strlen(observed);
	char **out, *digits[8];
	for (*count = 1, i = 0; observed[i]; i++)
		*count *= strlen(digits[i] = tab[observed[i] - '0']);
	out = malloc((*count + 1) * sizeof(char *));
	for (i = 0; i < *count; i++) {
		(out[i] = malloc(10))[sz] = 0;
		for (carry = 1, j = sz - 1; j >= 0; j--) {
			if (!*(digits[j] += carry))
				digits[j] = tab[observed[j] - '0'];
			else
				carry = 0;
			out[i][j] = *digits[j];
		};
	};
	out[*count] = NULL;
	return out;
}

void
free_pins(char **pins)
{
	for (int i = 0; pins[i] != NULL; i++)
		free(pins[i]);
	free(pins);
}
