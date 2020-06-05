// 6 kyu
// Equal Sides Of An Array


int
find_even_index(const int *arr, int sz)
{
	int rsum, lsum, i;
	for (i = rsum = 0; i < sz; rsum += arr[i], i++)
		;
	for (i = lsum = 0; i < sz; lsum += arr[i], i++)
		if ((rsum -= arr[i]) == lsum)
			return i;
	return -1;
}
