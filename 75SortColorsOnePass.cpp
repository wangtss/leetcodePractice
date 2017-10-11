void sortColors(vector<int>& nums) {
	int len = nums.size(), index_r = 0, index_w = 0, index_b = 0 ,temp;
	for (; index_b < len; ++index_b) {
		temp = nums[index_b];
		nums[index_b] = 2;
		if (temp < 2) nums[index_w++] = 1;
		if (temp < 1) nums[index_r++] = 0;
	}
}