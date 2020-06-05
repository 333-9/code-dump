// 5 kyu
// Report total allocated memory II


alloc_sz = 0;

get_currently_allocated_size()
{
	return alloc_sz;
}

*mem_alloc(sz)
{
	int *p;
	alloc_sz += sz;
	*(p = malloc(sizeof(int) + sz)) = sz;
	return ++p;
}

mem_free(p) int *p;
{
	if (p)
		alloc_sz -= *--p;
	free(p);
}
