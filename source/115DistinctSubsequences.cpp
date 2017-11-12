int numDistinct(string s, string t) {
	int len_s = s.size(), len_t = t.size();
	vector<vector<int>> dp(len_s + 1, vector<int>(len_t + 1, 1));
	for (int index = 0; index <= len_s; ++index) dp[index][0] = 1;
	for (int index = 1; index <= len_t; ++index) dp[0][index] = 0;
	for (int index_s = 1; index_s <= len_s; ++index_s) {
		for (int index_t = 1; index_t <= len_t; ++index_t) {
			dp[index_s][index_t] = dp[index_s - 1][index_t];
			if (s.at(index_s - 1) == t.at(index_t - 1)) dp[index_s][index_t] += dp[index_s - 1][index_t - 1];
		}
	}
	return dp[len_s][len_t];
}