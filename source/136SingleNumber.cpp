int singleNumber(vector<int>& nums) {
	int result = 0;
	for (auto index : nums) {
		result ^= index;
	}
	return result;
}