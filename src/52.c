// 6 kyu
// Highest Scoring Word


#include <stdlib.h>
#include <string.h>

#define LONGEST_WORD 0xff /* taken from wikipedia */
char *
highestScoringWord(const char *str)
{
	size_t word_sz = LONGEST_WORD;
	char *word = malloc(word_sz + 1);
	short h_score = 0, c_score = 0;
	const char *word_begining;
	for (word_begining = str;; str++) {
		if (*str == ' ') {
			if (c_score > h_score) {
				h_score = c_score;
				if (word_sz < (size_t)(str - word_begining)) {
					word_sz = (size_t)(str - word_begining);
					word = realloc(word, word_sz + 1);
				};
				memcpy(word, word_begining,
				       (size_t)(str - word_begining));
				word[(size_t)(str - word_begining)] = '\0';
			};
			c_score = 0;
			word_begining = str + 1;
		} else if (*str == '\0') {
			if (c_score > h_score)
				memcpy(word, word_begining,
				       (size_t)(str - word_begining) + 1);
			return word;
		} else {
			c_score += *str - ('a' - 1);
		};
	};
}
