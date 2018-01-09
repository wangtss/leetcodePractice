vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.empty()) return {};
	int len = nums.size();
	vector<int> m1(len, 1), m2(len, 1);
	for (int index = 1; index < len; ++index) {
		m1[index] = m1[index - 1] * nums[index - 1];
	}
	for (int index = len - 2; index >= 0; --index) {
		m2[index] = m2[index + 1] * nums[index + 1];
	}
	vector<int> res;
	for (int index = 0; index < len; ++index) {
		res.push_back(m1[index] * m2[index]);
	}
	return res;
}