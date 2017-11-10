vector<vector<string>> partition(string s) {
	vector<vector<string>> result;
	vector<string> cur;
	helper_partition(s, result, cur, 0);
	return result;
}
void helper_partition(string s, vector<vector<string>>& result, vector<string>& cur, int pos) {
	if (pos == s.size()) {
		result.push_back(cur);
		return;
	}
	for (int index = pos; index < s.size(); ++index) {
		string temp = s.substr(pos, index - pos + 1);
		if (isPalindrome(temp)) {
			cur.push_back(temp);
			helper_partition(s, result, cur, index + 1);
			cur.pop_back();
		}
	}
}
bool isPalindrome(string s) {
	if (s.empty()) return true;
	int left = 0, right = s.size() - 1;
	while (left < right) {
		if (s.at(left++) != s.at(right--)) return false;
	}
	return true;
}