int minDepth(TreeNode* root) {
	if (!root) return 0;
	queue<TreeNode*> node;
	node.push(root);
	int count = 0, height = 0;
	while (!node.empty()) {
		height++;
		count = node.size();
		for (int index = 0; index < count; ++index) {
			TreeNode* temp = node.front();
			node.pop();
			if (!temp->left && !temp->right) return height;
			if (temp->left) node.push(temp->left);
			if (temp->right) node.push(temp->right);
		}
	}
	return height;
}