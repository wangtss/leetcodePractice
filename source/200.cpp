void numIsLands(vector<vector<char>>& grid, int start_row, int start_col, int row, int col) {
	if (start_row > row || start_col > col || start_row < 0 || start_col < 0 || grid[start_row][start_col] == '0') return;
	grid[start_row][start_col] = '0';
	numIsLands(grid, start_row + 1, start_col, row, col);
	numIsLands(grid, start_row - 1, start_col, row, col);
	numIsLands(grid, start_row, start_col + 1, row, col);
	numIsLands(grid, start_row, start_col - 1, row, col);
}
int numIslands(vector<vector<char>>& grid) {
	if (grid.empty()) return 0;
	int row = grid.size(), col = grid[0].size(), result = 0;
	for (int index_row = 0; index_row < row; ++index_row) {
		for (int index_col = 0; index_col < col; ++index_col) {
			if (grid[index_row][index_col] == '1') {
				result++;
				numIsLands(grid, index_row, index_col, row - 1, col - 1);
			}
		}
	}
	return result;
}