void combine_helper(int n, int k, int begin, vector<int>& combination, vector<vector<int>>& result) {
	if (combination.size() == k) {
		result.push_back(combination);
		return;
	}
	for (; begin <= n; ++begin) {
		combination.push_back(begin);
		combine_helper(n, k, begin + 1, combination, result);
		combination.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
	vector<int> combination;
	vector<vector<int>> result;
	combine_helper(n, k, 1, combination, result);
	return result;
}