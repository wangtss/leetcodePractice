int maxDepth(TreeNode* root) {
	if (root == NULL) return 0;
	queue<TreeNode *> q;
	q.push(root);
	int result = 0, count;
	while (!q.empty()) {
		result++;
		count = q.size();
		for (int index = 0; index < count; ++index) {
			TreeNode *temp = q.front();
			q.pop();
			if (temp->left != NULL) q.push(temp->left);
			if (temp->right != NULL) q.push(temp->right);
		}
	}
	return result;
}