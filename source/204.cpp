int countPrimes(int n) {
	if (n < 3) return 0;
	vector<bool> p(n, true);
	for (int index = 2; index * index < n; ++index) {
		if (p[index]) {
			for (int j = 2; index * j < n; ++j) {
				p[j * index] = false;
			}
		}
	}
	int result = 0;
	for (int index = 2; index < n; ++index) {
		if (p[index]) result++;
	}
	return result;
}