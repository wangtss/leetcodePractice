int maxProduct(vector<int>& nums) {
	if (nums.empty()) return 0;
	int len = nums.size(), global;
	vector<int> local_min(len, 0), local_max(len, 0);
	local_min[0] = local_max[0] = global = nums[0];
	for (int index = 1; index < len; ++index) {
		local_max[index] = max(max(local_max[index - 1] * nums[index], nums[index]), nums[index] * local_min[index - 1]);
		local_min[index] = min(min(local_min[index - 1] * nums[index], nums[index]), nums[index] * local_max[index - 1]);
		global = max(global, local_max[index]);
	}
	return global;
}