int minDistance(string word1, string word2) {
	int len_f = word1.length(), len_s = word2.length();
	vector<vector<int>> dp(len_f + 1, vector<int>(len_s + 1, 0));
	for (int index = 0; index <= len_f; ++index) dp[index][0] = index;
	for (int index = 0; index <= len_s; ++index) dp[0][index] = index;
	for (int index_f = 1; index_f <= len_f; ++index_f) {
		for (int index_s = 1; index_s <= len_s; ++index_s) {
			if (word1[index_f - 1] == word2[index_s - 1]) dp[index_f][index_s] = dp[index_f - 1][index_s - 1];
			else dp[index_f][index_s] = dp[index_f - 1][index_s - 1] + 1;
			dp[index_f][index_s] = min(dp[index_f][index_s], min(dp[index_f][index_s - 1] + 1, dp[index_f - 1][index_s] + 1));
		}
	}
	return dp[len_f][len_s];
}