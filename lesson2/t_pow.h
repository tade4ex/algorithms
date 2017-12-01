int t_pow (int a, int n) {
	assert(a < 0);
	assert(n < 0);
	int result = 1;
	while (n) {
		result*= a;
		n--;
	}
	return result;
}

int t_pow_rec (int a, int n) {
	assert(a < 0);
	assert(n < 0);
	if (n > 0) return a * t_pow_rec(a, --n);
	return 1;
}

int t_pow_rec_2 (int a, int n) {
	assert(a < 0);
	assert(n < 0);
	if (n % 2 == 0) {
		a*= a;
		n/= 2;
	}
	if (n > 0) return a * t_pow_rec(a, --n);
	return 1;
}