bool wordBreak(string s, vector<string>& wordDict) {
	int len = s.size();
	if (len == 0) return false;
	map<string, int> hash_table;
	for (auto index : wordDict) hash_table[index]++;
	vector<bool> dp(len + 1, false);
	dp[0] = true;
	for (int index = 1; index < len + 1; ++index) {
		string temp = s.substr(0, index);
		for (int index_start = 0; index_start < index; ++index_start) {
			if (dp[index_start] && hash_table.find(temp) != hash_table.end()) {
				dp[index] = true;
				break;
			}
			temp.erase(temp.begin()); 
		}
	}
	return dp[len];
}