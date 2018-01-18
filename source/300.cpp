int lengthOfLIS(vector<int>& nums) {
	int res = 0, len = nums.size();
	vector<int> dp(len, 1);
	int res = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		res = max(res, dp[i]);
	}
	return res;
}