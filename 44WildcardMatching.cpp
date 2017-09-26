bool isMatch(string s, string p) {
	int len_s = s.length() + 1, len_p = p.length() + 1;
	if (len_p > 30000) return false;
	vector<vector<bool>> dp(len_s, vector<bool>(len_p, false));
	dp[0][0] = true;
	for (int index_s = 0; index_s < len_s; ++index_s) {
		for (int index_p = 1; index_p < len_p; ++index_p) {
			if (p[index_p - 1] == '*')
				dp[index_s][index_p] = dp[index_s][index_p - 1] || (index_s > 0 && dp[index_s - 1][index_p]);
			else dp[index_s][index_p] = index_s > 0 && dp[index_s - 1][index_p - 1] && (s[index_s - 1] == p[index_p - 1] || p[index_p - 1] == '?');
		}
	}
	return dp[s.length()][p.length()];
}