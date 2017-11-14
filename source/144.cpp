vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	if (!root) return result;
	stack<TreeNode*> node;
	node.push(root);
	while (!node.empty()) {
		int count = node.size();
		for (int index = 0; index < count; ++index) {
			TreeNode *temp = node.top();
			node.pop();
			result.push_back(temp->val);
			if (temp->right) node.push(temp->right);
			if (temp->left) node.push(temp->left);
		}
	}
	return result;
}