void rotate(vector<int>& nums, int k) {
	int len = nums.size();
	if (!len || k % len == 0) return;
	k = k % len;
	reverse(nums.begin(), nums.begin() + len - k);
	reverse(nums.begin() + len - k, nums.end());
	reverse(nums.begin(), nums.end());
}