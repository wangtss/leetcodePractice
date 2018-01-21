	int maxProfit(vector<int>& prices) {
		int day = prices.size();
		if (day <= 0) return 0;
		vector<int> buy(day, 0), sell(day, 0);
		buy[0] = -prices[0];
		sell[0] = 0;
		for (int i = 1; i < day; ++i) {
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
			buy[i] = max(buy[i - 1], (i >= 2 ? sell[i - 2] : 0) - prices[i]);
		}
		return sell[day - 1];
	}