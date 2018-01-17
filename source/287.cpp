	int findDuplicate(vector<int>& nums) {
		int l = 0, r = nums.size() - 1, mid = 0;
		while (l <= r) {
			mid = l + (r - l) / 2;
			int count = 0;
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] <= mid) ++count;
			}
			if (count > mid) r = mid - 1;
			else l = mid + 1;
		}
		return l;
	}