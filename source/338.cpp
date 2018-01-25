	vector<int> countBits(int num) {
		if (num < 1) return { 0 };
		vector<int> dp(num + 1, 0);
		dp[1] = 1;
		int index_inter = 1, index_intra = 0;
		for (int i = 2; i <= num; ++i) {
			dp[i] = dp[index_intra] + 1;
			index_intra++;
			if (index_intra == pow(2, index_inter)) {
				index_inter++;
				index_intra = 0;
			}
		}
		return dp;
	}