int maxProfit(vector<int>& prices) {
	if (prices.size() < 1) return 0;
	int maxTransTime = 2, diff = 0;
	vector<int> global(3, 0), local(3, 0);
	for (int indexDay = 0; indexDay < prices.size() - 1; ++indexDay) {
		diff = prices[indexDay + 1] - prices[indexDay];
		for (int indexTrans = maxTransTime; indexTrans >= 1; --indexTrans) {
			local[indexTrans] = max(global[indexTrans - 1] + max(diff, 0), local[indexTrans] + diff);
			global[indexTrans] = max(local[indexTrans], global[indexTrans]);
		}
	}
	return global[2];
}