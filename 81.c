// 6 kyu
// Bit Counting


#include <stddef.h>

size_t
countBits(unsigned value)
{
	return (value ? (value & 1) + countBits(value >> 1) : 0);
};
