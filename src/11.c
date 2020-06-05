// 5 kyu
// C Puzzle: Extract Field from a Double Value


int
exponent(double d)
{
	union {
		struct {
			unsigned long m : 52;
			unsigned long e : 11;
			unsigned long s : 1;
		} m;
		double d;
	} u;
	u.d = d;
	return u.m.e;
}
