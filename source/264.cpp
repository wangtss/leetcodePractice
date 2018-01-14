int nthUglyNumber(int n) {
	vector<int> res(1, 1);
	int i2 = 0, i3 = 0, i5 = 0;
	while (res.size() < n) {
		int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
		int loc = min(m2, min(m3, m5));
		if (m2 == loc) i2++;
		if (m3 == loc) i3++;
		if (m5 == loc) i5++;
		res.push_back(loc);
	}
	return res.back();
}