int majorityElement(vector<int>& nums) {
	int len = nums.size();
	map<int, int> hash_table;
	for (int index = 0; index < len; ++index) {
		hash_table[nums[index]]++;
		if (hash_table[nums[index]] > len / 2) return nums[index];
	}
}