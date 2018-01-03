	int quickSplit(vector<int>& nums, int l, int h)  {
		int pivot = nums[l];
		while (l < h) {
			while (l < h && pivot >= nums[h]) h--;
			nums[l] = nums[h];
			while (l < h && pivot <= nums[l]) l++;
			nums[h] = nums[l];
		}
		nums[l] = pivot;
		return l;
	}
	int findKthLargest(vector<int>& nums, int k) {
		int l = 0, h = nums.size() - 1;
		while (true) {
			int pos = quickSplit(nums, l, h);
			if (pos == k - 1) return nums[pos];
			else if (pos > k - 1) h = pos - 1;
			else l = pos + 1;
		}
	}