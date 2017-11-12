vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;
	vector<int> cur;
	deque<TreeNode *> node;
	TreeNode *temp;
	if (root == NULL) return result;
	node.push_back(root);
	int flag = 0;
	while (!node.empty()) {
		int count = node.size();
		cur.clear();
		for (int index = 0; index < count; ++index) {
			if (!(flag % 2)) {
				temp = node.front();
				node.pop_front();
				if (temp->left != NULL) node.push_back(temp->left);
				if (temp->right != NULL) node.push_back(temp->right);
			}
			else {
				temp = node.back();
				node.pop_back();
				if (temp->right != NULL) node.push_front(temp->right);
				if (temp->left != NULL) node.push_front(temp->left);
			}
			cur.push_back(temp->val);
		}
		flag++;
		result.push_back(cur);
	}
	return result;
}