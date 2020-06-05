// 5 kyu
// int32 to IPv4


#include <inttypes.h>
#include <stdio.h>

void
uint32_to_ip(uint32_t ip, char *output)
{
	sprintf(output, "%i.%i.%i.%i", (ip & 0xff000000) >> 24,
	        (ip & 0xff0000) >> 16, (ip & 0xff00) >> 8, (ip & 0xff));
}
