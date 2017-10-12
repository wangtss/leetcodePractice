void subsets_helper(vector<int>& nums, int k, int begin, vector<int>& combination, vector<vector<int>>& result) {
	if (combination.size() == k) {
		result.push_back(combination);
		return;
	}
	for (; begin < nums.size(); ++begin) {
		combination.push_back(nums[begin]);
		subsets_helper(nums, k, begin + 1, combination, result);
		combination.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<int> combination;
	vector<vector<int>> result;
	for (int k = 0; k <= nums.size(); ++k) {
		subsets_helper(nums, k, 0, combination, result);
	}
	return result;
}