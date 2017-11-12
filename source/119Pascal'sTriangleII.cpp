vector<int> getRow(int rowIndex) {
	rowIndex++;
	vector<int> result;
	result.push_back(1);
	int count = 2;
	for (int indexRow = 1; indexRow < rowIndex; ++indexRow) {
		vector<int> cur(count, 0);
		for (int indexCol = 0; indexCol < count; ++indexCol) {
			if (indexCol >= 1)
				cur[indexCol] += result[indexCol - 1];
			if (indexCol < count - 1)
				cur[indexCol] += result[indexCol];
		}
		result = cur;
		count++;
	}
	return result;
}