int countLiveNeighbors(vector<vector<int>> board, int i, int j) {
	int res = 0, next = board[i][j];
	if (board[i - 1][j - 1]) res++;
	if (board[i - 1][j]) res++;
	if (board[i - 1][j + 1]) res++;
	if (board[i][j - 1]) res++;
	if (board[i][j + 1]) res++;
	if (board[i + 1][j - 1]) res++;
	if (board[i + 1][j]) res++;
	if (board[i + 1][j + 1]) res++;
	if (next && (res < 2 || res > 3)) next = 0;
	if (!next && res == 3) next = 1;
	return next;
}
void gameOfLife(vector<vector<int>>& board) {
	int row = board.size();
	if (row == 0) return;
	int col = board[0].size();
	if (col == 0) return;
	vector<vector<int>> copy(row + 2, vector<int>(col + 2, 0));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			copy[i + 1][j + 1] = board[i][j];
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			board[i][j] = countLiveNeighbors(copy, i + 1, j + 1);
		}
	}
}