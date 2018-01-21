	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> res;
		int min_len = n + 1, cur_len = 0;
		map<int, vector<int>> graph;
		for (int i = 0; i < edges.size(); ++i) {
			graph[edges[i].first].push_back(edges[i].second);
			graph[edges[i].second].push_back(edges[i].first);
		}
		for (int i = 0; i < n; ++i) {
			cur_len = 0;
			queue<int> bfs;
			bfs.push(i);
			vector<int> hash(n ,0);
			while (!bfs.empty()) {
				int bfs_len = bfs.size();
				for (int index_len = 0; index_len < bfs_len; ++index_len) {
					int node = bfs.front();
					bfs.pop();
					hash[node] = 1;
					for (int j = 0; j < graph[node].size(); ++j) {
						if (!hash[graph[node][j]]) {
							bfs.push(graph[node][j]);
						}
					}
				}
				cur_len++;
			}
			if (cur_len < min_len) {
				min_len = cur_len;
				res.clear();
				res.push_back(i);
			}
			else if (cur_len == min_len) res.push_back(i);
		}
		return res;
	}
		vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (edges.empty()) return {};
		vector<int> res;
		map<int, vector<int>> graph;
		for (int i = 0; i < edges.size(); ++i) {
			graph[edges[i].first].push_back(edges[i].second);
			graph[edges[i].second].push_back(edges[i].first);
		}
		queue<int> search;
		for (int i = 0; i < n; ++i) {
			if (graph[i].size() == 1) search.push(i);
		}
		while (n > 2) {
			int len = search.size();
			for (int i = 0; i < len; ++i) {
				int node = search.front();
				search.pop();
				for (auto a : graph[node]) {
					graph[a].erase(find(graph[a].begin(), graph[a].end(), node));
					if (graph[a].size() == 1) search.push(a);
				}
				n--;
			}
		}
		while (!search.empty()) {
			res.push_back(search.front());
			search.pop();
		}
		return res;
	}