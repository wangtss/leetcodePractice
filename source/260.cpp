vector<int> singleNumber(vector<int>& nums) {
	if (nums.empty()) return {};
	int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
	diff &= -diff;
	vector<int> res(2, 0);
	for (auto i : nums) {
		if (i & diff) {
			res[0] ^= i;
		}
		else {
			res[1] ^= i;
		}
	}
	return res;
}