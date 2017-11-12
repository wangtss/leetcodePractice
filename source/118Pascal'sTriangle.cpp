vector<vector<int>> generate(int numRows) {
	vector<vector<int>> result;
	int count = 1;
	for (int indexRow = 0; indexRow < numRows; ++indexRow) {
		vector<int> cur(count, 0);
		for (int indexCol = 0; indexCol < count; ++indexCol) {
			if (indexRow >= 1) {
				if (indexCol >= 1) 
					cur[indexCol] += result[indexRow - 1][indexCol - 1];
				if (indexCol < count - 1)
					cur[indexCol] += result[indexRow - 1][indexCol];
			}
			else cur[indexCol] = 1;
			//cur[indexCol] = indexRow >= 1 ? (indexCol < count - 1 ? result[indexRow - 1][indexCol] : 0 + (indexCol >= 1 ? result[indexRow - 1][indexCol - 1] : 0)) : (1);
		}
		result.push_back(cur);
		count++;
	}
	return result;
}