// 5 kyu
// Beeramid


// Returns number of complete beeramid levels
int
beeramid(double bonus, double price)
{
	int i;
	bonus -= price;
	for (i = 2; bonus >= 0; i++) {
		bonus -= price * i * i;
	};
	return (i - 2);
}
