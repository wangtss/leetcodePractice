int numDecodings(string s) {
	if (s.empty() || s[0] == '0') return 0;
	int len = s.size();
	vector<int> dp(len + 1, 1);
	for (int index = 1; index <= len; ++index) {
		if (s[index - 1] == '0') {
			if (s[index - 2] == '0' || stoi(s.substr(index - 2, 1)) > 2) return 0;
			else dp[index] = dp[index - 2];
		}
		else dp[index] = (index > 1 && s[index - 2] != '0' && stoi(s.substr(index - 2, 2)) <= 26) ? dp[index - 1] + dp[index - 2] : dp[index - 1];
	}
	return dp.back();
}