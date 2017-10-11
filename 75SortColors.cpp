void sortColors(vector<int>& nums) {
	int len = nums.size(), index_r = 0, index_w = 0, index_b = 0;
	for (int index = 0; index < len; ++index) {
		if (nums[index] == 0) index_r++;
		else if (nums[index] == 1) index_w++;
		else index_b++;
	}
	for (int index = 0; index < len; ++index) {
		if (index_r-- > 0) nums[index] = 0;
		else if (index_w-- > 0) nums[index] = 1;
		else nums[index] = 2;
	}
}