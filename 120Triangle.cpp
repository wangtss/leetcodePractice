int minimumTotal(vector<vector<int>>& triangle) {
	int len = triangle.size();
	if (len < 0 || triangle[0].size() < 0) return 0;
	vector<vector<int>> dp(len, vector<int>(len, 0));
	dp[0][0] = triangle[0][0];
	for (int indexRow = 1; indexRow < len; ++indexRow) {
		for (int indexCol = 0; indexCol <= indexRow; ++indexCol) {
			dp[indexRow][indexCol] = triangle[indexRow][indexCol];
			if (indexCol >= 1 && indexCol < indexRow) dp[indexRow][indexCol] += min(dp[indexRow - 1][indexCol - 1], dp[indexRow - 1][indexCol]);
			else if (indexCol < 1) dp[indexRow][indexCol] += dp[indexRow - 1][indexCol];
			else dp[indexRow][indexCol] += dp[indexRow - 1][indexCol - 1];
		}
 	}
	int result = dp[len - 1][0];
	for (int index = 1; index < len; ++index) result = result > dp[len - 1][index] ? dp[len - 1][index] : result;
	return result;
}