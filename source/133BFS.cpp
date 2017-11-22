UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (!node) return NULL;
	map<UndirectedGraphNode*, UndirectedGraphNode*> hash_table;
	UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
	hash_table[node] = copy;
	queue<UndirectedGraphNode*> node_queue;
	node_queue.push(node);
	while (!node_queue.empty()) {
		UndirectedGraphNode *cur = node_queue.front();
		node_queue.pop();
		for (int index_neighbors = 0; index_neighbors < cur->neighbors.size(); ++index_neighbors) {
			if (hash_table.find(cur->neighbors[index_neighbors]) == hash_table.end()) {
				UndirectedGraphNode *shit = new UndirectedGraphNode(cur->neighbors[index_neighbors]->label);
				hash_table[cur->neighbors[index_neighbors]] = shit;
				node_queue.push(cur->neighbors[index_neighbors]);
			}
			hash_table[cur]->neighbors.push_back(hash_table[cur->neighbors[index_neighbors]]);
		}
	}
	return hash_table[node];
}