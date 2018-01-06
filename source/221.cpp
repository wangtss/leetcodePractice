int maximalSquare(vector<vector<char>>& matrix) {
	int row = matrix.size();
	if (!row) return 0;
	int col = matrix[0].size();
	if (!col) return 0;
	vector<vector<int>> dp(row, vector<int>(col, 0));
	for (int index_row = 0; index_row < row; ++index_row) dp[index_row][0] = matrix[index_row][0] - '0';
	for (int index_col = 0; index_col < col; ++index_col) dp[0][index_col] = matrix[0][index_col] - '0';
	for (int index_row = 1; index_row < row; ++index_row) {
		for (int index_col = 1; index_col < col; ++index_col) {
			if (matrix[index_row][index_col] == '1') {
				dp[index_row][index_col] = min(dp[index_row - 1][index_col - 1], min(dp[index_row][index_col - 1], dp[index_row - 1][index_col])) + 1;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			res = max(res, dp[i][j]);
		}
	}
	return res * res;
}