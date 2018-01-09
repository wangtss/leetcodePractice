vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.empty()) return {};
	int len = nums.size(), pre = 1;
	vector<int> res(len, 1);
	for (int index = 0; index < len; ++index) {
		res[index] *= pre;
		pre *= nums[index];
	}
	pre = 1;
	for (int index = len - 1; index >= 0; --index) {
		res[index] *= pre;
		pre *= nums[index];
	}
	return res;
}