int largestRectangleArea(vector<int>& heights) {
	stack<int> order;
	order.push(0);
	int len = heights.size(), maxArea = -1, count = 0;
	for (int index = 0; index < len; ++index) {
		if (heights[index] >= order.top()) {
			order.push(heights[index]);
		}
		else {
			count = 0;
			while (heights[index] < order.top()) {
				maxArea = max(maxArea, order.top() * ++count);
				order.pop();
			}
			while (count-- > 0) order.push(heights[index]);
			order.push(heights[index]);
		}
	}
	count = 0;
	while (!order.empty()) {
		maxArea = max(maxArea, order.top() * ++count);
		order.pop();
	}
	return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.empty() || matrix[0].empty()) return 0;
	int row = matrix.size(), col = matrix[0].size(), result = 0;
	vector<int> hist(col, 0);
	for (int index_row = 0; index_row < row; ++index_row) {
		for (int index_col = 0; index_col < col; ++index_col) {
			if (matrix[index_row][index_col] == '1') hist[index_col]++;
			else hist[index_col] = 0;
		}
		result = max(result, largestRectangleArea(hist));
	}
	return result;
}