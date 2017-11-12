int minPathSum(vector<vector<int>>& grid) {
	int row = grid.size();
	if (row == 0) return 0;
	int col = grid[0].size();
	vector<vector<int>> dp = grid;
	for (int index_row = 0; index_row < row; ++index_row) {
		for (int index_col = 0; index_col < col; ++index_col) {
			if (!(index_row == 0 && index_col == 0)){
				if (index_row - 1 < 0) dp[index_row][index_col] += dp[index_row][index_col - 1];
				else if (index_col - 1 < 0) dp[index_row][index_col] += dp[index_row - 1][index_col];
				else {
					dp[index_row][index_col] += min(dp[index_row - 1][index_col], dp[index_row][index_col - 1]);
				}
			}
		}
	}
	return dp[row - 1][col - 1];
}