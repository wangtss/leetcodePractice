void solve(vector<vector<char>>& board) {
	if (board.empty() || board[0].empty()) return;
	int row = board.size(), col = board[0].size();
	queue<vector<int>> edge;
	for (int index_row = 0; index_row < row; ++index_row) {
		if (board[index_row][0] == 'O') edge.push({ index_row, 0 });
		if (board[index_row][col - 1] == 'O') edge.push({ index_row, col - 1 });
	}
	for (int index_col = 1; index_col < col - 1; ++index_col) {
		if (board[0][index_col] == 'O') edge.push({ 0, index_col });
		if (board[row - 1][index_col] == 'O') edge.push({ row - 1, index_col });
	}
	while (!edge.empty()) {
		int count = edge.size();
		for (int index_queue = 0; index_queue < count; ++index_queue) {
			vector<int> temp = edge.front();
			edge.pop();
			board[temp[0]][temp[1]] = '#';
			if (temp[0] - 1 >= 0 && board[temp[0] - 1][temp[1]] == 'O') edge.push({ temp[0] - 1, temp[1] });
			if (temp[0] + 1 < row && board[temp[0] + 1][temp[1]] == 'O') edge.push({ temp[0] + 1, temp[1] });
			if (temp[1] - 1 >= 0 && board[temp[0]][temp[1] - 1] == 'O') edge.push({ temp[0], temp[1] - 1 });
			if (temp[1] + 1 < col && board[temp[0]][temp[1] + 1] == 'O') edge.push({ temp[0], temp[1] + 1 });
		}
	}
	for (int index_row = 0; index_row < row; ++index_row) {
		for (int index_col = 0; index_col < col; ++index_col) {
			if (board[index_row][index_col] == '#') board[index_row][index_col] = 'O';
			else if (board[index_row][index_col] == 'O') board[index_row][index_col] = 'X';
		}
	}
}