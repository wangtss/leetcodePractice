int singleNumber(vector<int>& nums) {
	int result = 0;
	for (int index_bit = 0; index_bit < 32; ++index_bit) {
		int sum = 0;
		for (int index_nums = 0; index_nums < nums.size(); ++index_nums) {
			sum += (nums[index_nums] >> index_bit) & 1;
		}
		result |= (sum % 3) << index_bit;
	}
	return result;
}