vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> result;
	vector<int> cur;
	queue<TreeNode *> node;
	TreeNode *temp;
	if (root == NULL) return result;
	node.push(root);
	while (!node.empty()) {
		int count = node.size();
		cur.clear();
		for (int index = 0; index < count; ++index) {
			temp = node.front();
			node.pop();
			if (temp->left != NULL) node.push(temp->left);
			if (temp->right != NULL) node.push(temp->right);
			cur.push_back(temp->val);
		}
		result.push_back(cur);
	}
	return result;
}