int maxProfit(vector<int>& prices) {
	if (prices.size() < 1) return 0;
	int minPrices = prices[0], maxDif = 0;
	for (int index = 1; index < prices.size(); ++index) {
		if (prices[index] < minPrices) minPrices = prices[index];
		else maxDif = max(maxDif, prices[index] - minPrices);
	}
	return maxDif;
}