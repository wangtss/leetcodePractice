int climbStairs(int n) {
	if (n <= 1) return 1;
	if (n == 2) return 2;
	vector<int> dp(n, 0);
	dp[0] = 1;
	dp[1] = 2;
	for (int index = 2; index < n; ++index) {
		dp[index] = dp[index - 1] + dp[index - 2];
	}
	return dp[n - 1];
}