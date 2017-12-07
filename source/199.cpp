vector<int> rightSideView(TreeNode* root) {
	if (!root) return {};
	stack<TreeNode*> input, output;
	input.push(root);
	vector<int> result;
	while (!input.empty()) {
		int count = input.size(), view = 0;
		for (int index = 0; index < count; ++index) {
			TreeNode *temp = input.top();
			input.pop();
			view = temp->val;
			if (temp->left) output.push(temp->left);
			if (temp->right) output.push(temp->right);
		}
		result.push_back(view);
		while (!output.empty()) {
			input.push(output.top());
			output.pop();
		}
	}
	return result;
}

vector<int> rightSideView(TreeNode* root) {
	if (!root) return {};
	queue<TreeNode*> bfs;
	bfs.push(root);
	vector<int> result;
	while (!bfs.empty()) {
		int count = bfs.size(), view = 0;
		for (int index = 0; index < count; ++index) {
			TreeNode *temp = bfs.front();
			bfs.pop();
			view = temp->val;
			if (temp->left) bfs.push(temp->left);
			if (temp->right) bfs.push(temp->right);
		}
		result.push_back(view);
	}
	return result;
}