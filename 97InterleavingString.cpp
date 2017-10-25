bool isInterleave(string s1, string s2, string s3) {
	if (s1.size() + s2.size() != s3.size()) return false;
	int row = s1.size() + 1, col = s2.size() + 1;
	vector<vector<bool>> result(row, vector<bool>(col, 1));
	for (int index = 1; index < row; ++index) result[index][0] = result[index - 1][0] && s1.at(index - 1) == s3.at(index - 1);
	for (int index = 1; index < col; ++index) result[0][index] = result[0][index - 1] && s2.at(index - 1) == s3.at(index - 1);
	for (int index_row = 1; index_row < row; ++index_row) {
		for (int index_col = 1; index_col < col; ++index_col) {
			result[index_row][index_col] = (result[index_row - 1][index_col] && s1.at(index_row - 1) == s3.at(index_row + index_col - 1) ||
				(result[index_row][index_col - 1] && s2.at(index_col - 1) == s3.at(index_row + index_col - 1)));
		}
	}
	return result[row - 1][col - 1];
}