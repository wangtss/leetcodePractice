	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, mid;
		while (left < right) {
			mid = (left + right) >> 1;
			if (nums[mid] < nums[mid + 1]) left = mid - 1;
			else right = mid;
		}
		return right;
	}