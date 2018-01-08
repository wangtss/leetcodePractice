vector<string> summaryRanges(vector<int>& nums) {
	if (nums.empty()) return {};
	vector<string> res;
	int len = nums.size(), i = 0;
	while (i < len) {
		int start = i;
		while (i + 1 < len && nums[i + 1] == nums[i] + 1) {
			i++;
		}
		if (i == start) {
			res.push_back(to_string(nums[i]));
		}
		else {
			res.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
		}
		i++;
	}
	return res;
}