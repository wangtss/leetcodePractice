int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	if (m == 0) return 0;
	int n = obstacleGrid[0].size();
	if (obstacleGrid[0][0] == 1) return 0;
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (obstacleGrid[i][j] != 1) {
				dp[i][j] += i - 1 >= 0 ? dp[i - 1][j] : 0;
				dp[i][j] += j - 1 >= 0 ? dp[i][j - 1] : 0;
			}
		}
	}
	return dp[m - 1][n - 1];
}