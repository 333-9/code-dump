// 7 kyu
// Function Lookup Table Access in C #2


int
lookup_table_access((**table)(int), int index, int arg)
{
	return (table[index])(arg);
}
