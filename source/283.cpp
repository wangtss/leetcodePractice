	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 0;
		while (i < nums.size()) {
			if (!nums[i]) i++;
			else nums[j++] = nums[i++];
		}
		while (j < nums.size()) nums[j++] = 0;
	}