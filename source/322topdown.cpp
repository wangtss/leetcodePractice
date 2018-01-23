	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, 0);
		return coinChange(coins, dp, amount);
	}
	int coinChange(vector<int> coins, vector<int>& dp, int amount) {
		if (amount == 0) return 0;
		if (amount < 0) return -1;
		if (dp[amount] != 0) return dp[amount];
		int min = INT_MAX;
		for (int i = 0; i < coins.size(); ++i) {
			int res = coinChange(coins, dp, amount - coins[i]);
			if (res >= 0 && res + 1 < min) min = res + 1;
		}
		dp[amount] = (min == INT_MAX) ? -1 : min;
		return dp[amount];
	}