bool exist_helper(int start_row, int start_col, vector<vector<char>>& board, int row, int col, string word, int begin, vector<vector<bool>>& path) {
	if (begin == word.size()) return true;
	if (start_row + 1 < row && path[start_row + 1][start_col] && board[start_row + 1][start_col] == word[begin]) {
		path[start_row + 1][start_col] = false;
		if (exist_helper(start_row + 1, start_col, board, row, col, word, begin + 1, path)) return true;
		path[start_row + 1][start_col] = true;
	}
	if (start_row - 1 >= 0 && path[start_row - 1][start_col] && board[start_row - 1][start_col] == word[begin]) {
		path[start_row - 1][start_col] = false;
		if (exist_helper(start_row - 1, start_col, board, row, col, word, begin + 1, path)) return true;
		path[start_row - 1][start_col] = true;
	}
	if (start_col + 1 < col && path[start_row][start_col + 1] && board[start_row][start_col + 1] == word[begin]) {
		path[start_row][start_col + 1] = false;
		if (exist_helper(start_row, start_col + 1, board, row, col, word, begin + 1, path)) return true;
		path[start_row][start_col + 1] = true;
	}
	if (start_col - 1 >= 0 && path[start_row][start_col - 1] && board[start_row][start_col - 1] == word[begin]) {
		path[start_row][start_col - 1] = false;
		if (exist_helper(start_row, start_col - 1, board, row, col, word, begin + 1, path)) return true;
		path[start_row][start_col - 1] = true;
	}
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	if (board.empty() || board[0].empty() || word.empty()) return false;
	char start = word.at(0);
	int row = board.size(), col = board[0].size();
	for (int index_r = 0; index_r < row; ++index_r) {
		for (int index_c = 0; index_c < col; ++index_c) {
			if (board[index_r][index_c] == start) {
				vector<vector<bool>> path(row, vector<bool>(col, true));
				path[index_r][index_c] = false;
				if (exist_helper(index_r, index_c, board, row, col, word, 1, path)) return true;
			}
		}
	}
	return false;
}