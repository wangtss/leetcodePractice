	void adjustHeap(vector<int>& nums, int s, int e) {
		int root = nums[s];
		for (int index = s * 2 + 1; index <= e; index = index * 2 + 1) {
			if (index < e && nums[index] < nums[index + 1]) index++;
			if (root > nums[index]) break;
			nums[s] = nums[index];
			s = index;
		}
		nums[s] = root;
	}
	void sortHeap(vector<int>& nums, int t) {
		int len = nums.size() - 1;
		for (int index = len / 2; index >= 0; --index) {
			adjustHeap(nums, index, len);
		}
		for (int index = len; index > len - t; --index) {
			swap(nums[index], nums[0]);
			adjustHeap(nums, 0, index - 1);
		}
	}
	int findKthLargest(vector<int>& nums, int k) {
		sortHeap(nums, k);
		return nums[nums.size() - k];
	}