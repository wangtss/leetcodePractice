class NumMatrix {
public:
	vector<vector<int>> dp;
	NumMatrix(vector<vector<int>> matrix) {
		dp = matrix;
		int row = matrix.size(), col = row == 0 ? 0 : matrix[0].size();
		for (int i = 1; i < row; ++i) {
			dp[i][0] = dp[i - 1][0] + matrix[i][0];
		}
		for (int j = 1; j < col; ++j) {
			dp[0][j] = dp[0][j - 1] + matrix[0][j];
		}
		for (int i = 1; i < row; ++i) {
			for (int j = 1; j < col; ++j) {
				dp[i][j] = matrix[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int cut_row = row1 > 0 ? dp[row1 - 1][col2] : 0;
		int cut_col = col1 > 0 ? dp[row2][col1 - 1] : 0;
		int cmp = row1 > 0 && col1 > 0 ? dp[row1 - 1][col1 - 1] : 0;
		return dp[row2][col2] - cut_row - cut_col + cmp;
	}
};