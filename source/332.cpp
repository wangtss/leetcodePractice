	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		vector<string> cur;
		map<string, vector<string>> graph;
		for (auto ticket : tickets) {
			graph[ticket.first].push_back(ticket.second);
		}
		findItinerary(graph, cur, "JFK");
		return vector<string> (cur.rbegin(), cur.rend());
	}
	void findItinerary(map<string, vector<string>> &graph, vector<string> &cur, string start) {
		sort(graph[start].begin(), graph[start].end());
		while (graph[start].size()) {
			string temp = graph[start][0];
			graph[start].erase(graph[start].begin());
			findItinerary(graph, cur, temp);
		}
		cur.push_back(start);
	}