bool isHappy(int n) {
	map<int, int> hash_table;
	int sum = 0;
	while (1) {
		while (n > 0) {
			sum += pow(n % 10, 2);
			n = n / 10;
		}
		if (sum == 1) return true;
		if (hash_table.find(sum) != hash_table.end()) return false;
		hash_table[sum]++;
		n = sum;
		sum = 0;
	}
}