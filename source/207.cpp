bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	if (!numCourses) return true;
	vector<vector<int>> graph(numCourses, vector<int>(0));
	vector<int> in(numCourses, 0);
	queue<int> out;
	for (auto index : prerequisites) {
		graph[index.second].push_back(index.first);
		in[index.first]++;
	}
	for (int index = 0; index < numCourses; ++index) {
		if (in[index] == 0) out.push(index);
	}
	while (!out.empty()) {
		int temp = out.front();
		out.pop();
		for (auto index : graph[temp]) {
			in[index]--;
			if (in[index] == 0) out.push(index);
		}
	}
	for (auto index : in) {
		if (index) return false;
	}
	return true;
}
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (!numCourses) return true;
		vector<vector<int>> graph(numCourses, vector<int>(0));
		for (auto index : prerequisites) {
			graph[index.first].push_back(index.second);
		}
		vector<int> visited(numCourses, 0);
		for (int index = 0; index < numCourses; ++index) {
			if (!canFinishDFS(index, graph, visited)) return false;
		}
		return true;
	}
	bool canFinishDFS(int cur, vector<vector<int>> &graph, vector<int> &visited) {
		if (visited[cur] == -1) return false;
		if (visited[cur] == 1) return true;
		visited[cur] = -1;
		for (auto index : graph[cur]) {
			if (!canFinishDFS(index, graph, visited)) return false;
		}
		visited[cur] = 1;
		return true;
	}