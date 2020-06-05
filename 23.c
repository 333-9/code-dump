// 7 kyu
// Function Lookup Table Access in C


int
lookup_table_access(int (**table)(int), int index, int arg)
{
	return table[index](arg);
}
