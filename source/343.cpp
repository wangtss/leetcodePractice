	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[2] = 1;
		for (int i = 3; i <= n; ++i) {
			for (int j = 2; j < i; ++j) {
				dp[i] = max(dp[i], max(j, dp[j]) * (i - j));
			}
		}
		return dp[n];
	}