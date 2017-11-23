int candy(vector<int>& ratings) {
	int n = ratings.size(), happy = 1, count = n;
	vector<int> candy(n, 1);
	for (int index = 1; index < n; ++index) {
		if (ratings[index] > ratings[index - 1]) {
			count += candy[index - 1] + 1 - candy[index];
			candy[index] = candy[index - 1] + 1;
		}
	}
	for (int index = n - 2; index >= 0; --index) {
		if (ratings[index] > ratings[index + 1] && candy[index] <= candy[index + 1]) {
			count += candy[index + 1] + 1 - candy[index];
			candy[index] = candy[index + 1] + 1;
		}
	}
	return count;
}