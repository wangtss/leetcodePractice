int shitmaxProfit(vector<int>& prices) {
	if (prices.size() < 1) return 0;
	int maxPro = 0;
	for (int index = 1; index < prices.size(); ++index) {
		maxPro += max(0, prices[index] - prices[index - 1]);
	}
	return maxPro;
}
int maxProfit(int k, vector<int>& prices) {
	if (prices.size() < 1) return 0;
	if (k > prices.size()) return shitmaxProfit(prices);
	int maxTransTime = k, diff = 0;
	vector<int> global(k + 1, 0), local(k + 1, 0);
	for (int indexDay = 0; indexDay < prices.size() - 1; ++indexDay) {
		diff = prices[indexDay + 1] - prices[indexDay];
		for (int indexTrans = maxTransTime; indexTrans >= 1; --indexTrans) {
			local[indexTrans] = max(global[indexTrans - 1] + max(diff, 0), local[indexTrans] + diff);
			global[indexTrans] = max(local[indexTrans], global[indexTrans]);
		}
	}
	return global[k];
}