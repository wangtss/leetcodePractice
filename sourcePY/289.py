def gameOfLife(self, board):
    row = len(board)
    col = len(board[0]) if row > 0 else 0
    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]
    for i in range(row):
        for j in range(col):
            count = 0
            for k in range(8):
                ix, jy = i + dx[k], j + dy[k]
                if ix < 0 or ix >= row or jy < 0 or jy >= col:
                    continue
                if board[ix][jy] == 1 or board[ix][jy] == 2:
                    count += 1
            if not board[i][j] and count == 3:
                board[i][j] = 3
            if board[i][j] and (count < 2 or count > 3):
                board[i][j] = 2
    for i in range(row):
        for j in range(col):
            board[i][j] = board[i][j] % 2