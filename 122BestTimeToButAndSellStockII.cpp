int maxProfit(vector<int>& prices) {
	if (prices.size() < 1) return 0;
	int maxPro = 0;
	for (int index = 1; index < prices.size(); ++index) {
		maxPro += max(0, prices[index] - prices[index - 1]);
	}
	return maxPro;
}