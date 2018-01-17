int missingNumber(vector<int>& nums) {
	int index = 0, exp_sum = 0, real_sum = 0;
	for (; index < nums.size(); ++index) {
		exp_sum += index;
		real_sum += nums[index];
	}
	exp_sum += index;
	return real_sum - exp_sum;
}