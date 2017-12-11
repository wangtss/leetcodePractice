int minSubArrayLen(int s, vector<int>& nums) {
	int min_len = 0, left = 0, right = 0, temp_sum = 0, len = nums.size();
	while (true) {
		while (right < len && temp_sum < s) temp_sum += nums[right++];
		if (temp_sum < s) return min_len;
		min_len = min_len == 0 ? (right - left) : min(min_len, (right - left));
		temp_sum -= nums[left++];
	}
}