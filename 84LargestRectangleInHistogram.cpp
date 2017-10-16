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