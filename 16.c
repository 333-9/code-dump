// 6 kyu
// Vasya - Clerk


#include <stdlib.h>
#include <stdbool.h>

int
tickets(size_t length, const int *people)
{
	int change[2] = { 0 };
	for (unsigned i = 0; i < length; i++) {
		if (people[i] == 25) {
			change[0]++;
		} else if (people[i] == 50) {
			change[0]--;
			change[1]++;
		} else {
			change[0] -= change[1] > 0 ? 1 : 3;
			change[1] -= change[1] > 0;
		};
		if (change[0] < 0)
			return false;
	};
	return true;
}
