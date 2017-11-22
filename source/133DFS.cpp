void helperCloneGraph(UndirectedGraphNode* node, map<UndirectedGraphNode*, UndirectedGraphNode*>& hash_table) {
	for (int index = 0; index < node->neighbors.size(); ++index) {
		UndirectedGraphNode *temp = node->neighbors[index];
		if (hash_table.find(temp) == hash_table.end()) {
			UndirectedGraphNode *copy = new UndirectedGraphNode(temp->label);
			hash_table[temp] = copy;
			helperCloneGraph(temp, hash_table);
		}
		hash_table[node]->neighbors.push_back(hash_table[temp]);
	}
}
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (!node) return NULL;
	map<UndirectedGraphNode*, UndirectedGraphNode*> hash_table;
	UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
	hash_table[node] = copy;
	helperCloneGraph(node, hash_table);
	return hash_table[node];
}