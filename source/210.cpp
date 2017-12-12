vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	if (numCourses == 0) return {};
	vector<vector<int>> graph(numCourses, vector<int>(0));
	vector<int> in(numCourses, 0), result;
	for (int index = 0; index < prerequisites.size(); ++index) {
		graph[prerequisites[index].second].push_back(prerequisites[index].first);
		in[prerequisites[index].first]++;
	}
	queue<int> order;
	for (int index = 0; index < numCourses; ++index) {
		if (in[index] == 0) order.push(index);
	}
	while (!order.empty()) {
		int out = order.front();
		result.push_back(out);
		order.pop();
		for (int index = 0; index < graph[out].size(); ++index) {
			in[graph[out][index]]--;
			if (in[graph[out][index]] == 0) order.push(graph[out][index]);
		}
	}
	if (result.size() == numCourses) return result;
	return{};
}