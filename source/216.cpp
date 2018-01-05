void combinationSum3(vector<vector<int>>& res, vector<int>& cur, int k, int target, int begin) {
	if (cur.size() == k) {
		if (target == 0) res.push_back(cur);
		return;
	}
	if (target < 0) return;
	for (int index = begin; index <= 9; ++index) {
		cur.push_back(index);
		combinationSum3(res, cur, k, target - index, index + 1);
		cur.pop_back();
	}
	return;
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> res;
	vector<int> cur;
	combinationSum3(res, cur, k, n, 1);
	return res;
}