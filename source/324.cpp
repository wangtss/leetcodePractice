	void wiggleSort(vector<int>& nums) {
		vector<int> temp = nums;
		int len = nums.size(), j = (len + 1) / 2, k = len;
		sort(temp.begin(), temp.end());
		for (int i = 0; i < len; ++i) {
			nums[i] = i & 1 ? temp[--k] : temp[--j];
		}
	}