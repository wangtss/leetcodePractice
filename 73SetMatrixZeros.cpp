void setZeroes(vector<vector<int>>& matrix) {
	map<int, int> row, col;
	int numRow = matrix.size();
	if (numRow == 0) return;
	int numCol = matrix[0].size();
	for (int index_row = 0; index_row < numRow; ++index_row) {
		for (int index_col = 0; index_col < numCol; ++index_col) {
			if (!matrix[index_row][index_col]) {
				row[index_row]++;
				col[index_col]++;
			}
		}
	}
	for (map<int, int>::iterator index_row = row.begin(); index_row != row.end(); ++index_row) {
		for (int index = 0; index < numCol; ++index) matrix[index_row->first][index] = 0;
	}
	for (map<int, int>::iterator index_col = col.begin(); index_col != col.end(); ++index_col) {
		for (int index = 0; index < numRow; ++index) matrix[index][index_col->first] = 0;
	}
	return;
}