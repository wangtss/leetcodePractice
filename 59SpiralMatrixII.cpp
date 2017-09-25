vector<vector<int>> generateMatrix(int n) {
	int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1, counter = 1, index_row, index_col;
	vector<vector<int>> result(n);
	for (int index = 0; index < n; ++index) result[index].resize(n);
	while (rowBegin <= rowEnd && colBegin <= colEnd) {
		for (index_col = colBegin; index_col <= colEnd; ++index_col) {
			result[rowBegin][index_col] = counter++;
		}
		rowBegin++;
		for (index_row = rowBegin; index_row <= rowEnd; ++index_row) {
			result[index_row][colEnd] = counter++;
		}
		colEnd--;
		if (rowBegin <= rowEnd) {
			for (index_col = colEnd; index_col >= colBegin; --index_col) {
				result[rowEnd][index_col] = counter++;
			}
		}
		rowEnd--;
		if (colBegin <= colEnd) {
			for (index_row = rowEnd; index_row >= rowBegin; --index_row) {
				result[index_row][colBegin] = counter++;
			}
		}
		colBegin++;
	}
	return result;
}