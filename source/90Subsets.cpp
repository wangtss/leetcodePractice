void subsets_helper(vector<int>& nums, int k, int begin, vector<int>& combination, vector<vector<int>>& result) {
	if (combination.size() == k) {
		result.push_back(combination);
		return;
	}
	for (int index = begin; index < nums.size(); ++index) {
		if (index != begin && nums[index] == nums[index - 1]) continue;
		combination.push_back(nums[index]);
		subsets_helper(nums, k, index + 1, combination, result);
		combination.pop_back();
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<int> combination;
	vector<vector<int>> result;
	for (int k = 0; k <= nums.size(); ++k) {
		subsets_helper(nums, k, 0, combination, result);
	}
	return result;
}