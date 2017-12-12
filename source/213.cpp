int rob(vector<int>& nums, int start, int end) {
	int len = end - start + 1;
	if (len < 1) return 0;
	if (len < 2) return nums[start];
	vector<int> dp(len, 0);
	dp[0] = nums[start];
	dp[1] = max(nums[start], nums[start + 1]);
	for (int i = 2; i < len; ++i) {
		dp[i] = max(nums[i + start] + dp[i - 2], dp[i - 1]);
	}
	return dp[len - 1];
}
int rob(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
}