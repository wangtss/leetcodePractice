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

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> pre_order;
	while (root || !pre_order.empty()) {
		if (root) {
			result.push_back(root->val);
			pre_order.push(root);
			root = root->left;
		}
		else {
			root = pre_order.top();
			pre_order.pop();
			root = root->right;
		}
	}
	return result;
}