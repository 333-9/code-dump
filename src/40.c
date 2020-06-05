// 5 kyu
// Report total allocated memory II #2


#include <stdlib.h>

struct mem_chunk {
	size_t size;
	char mem[];
};

unsigned long long currently_allocated_mem = 0;

unsigned long long
get_currently_allocated_size(void)
{
	return (currently_allocated_mem);
}

void *
mem_alloc(size_t size)
{
	struct mem_chunk *p = malloc(sizeof(struct mem_chunk) + size);
	p->size = size;
	currently_allocated_mem += size;
	return (&(p->mem));
}

void
mem_free(void *p)
{
	if (p == NULL)
		return;
	p -= sizeof(size_t);
	currently_allocated_mem -= ((struct mem_chunk *)p)->size;
	free(p);
}
