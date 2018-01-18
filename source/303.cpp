class NumArray {
private:
	vector<int> dp;
public:
	NumArray(vector<int> nums) {
		int len = nums.size();
		dp = nums;
		for (int i = 1; i < len; ++i) {
			dp[i] = dp[i - 1] + nums[i];
		}
	}

	int sumRange(int i, int j) {
		return i == 0 ? dp[j] : dp[j] - dp[i - 1];
	}
};