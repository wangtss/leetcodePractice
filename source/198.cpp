int rob(vector<int>& nums) {
	int len = nums.size();
	if (len < 1) return 0;
	if (len < 2) return nums[0];
	vector<int> dp(len, 0);
	dp[0] = nums[0];
	dp[1] = nums[1];
	for (int i = 2; i < len; ++i) {
		dp[i] = nums[i] + dp[i - 2];
		if (i > 2) dp[i] = max(dp[i], dp[i - 3] + nums[i]);
	}
	return max(dp[len - 1], dp[len - 2]);
}