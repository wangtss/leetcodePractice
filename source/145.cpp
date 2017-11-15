vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> post_order;
	TreeNode *pre = NULL;
	while (root || !post_order.empty()) {
		if (root) {
			post_order.push(root);
			root = root->left;
		}
		else {
			TreeNode* top = post_order.top();
			if (top->right && pre != top->right) {
				root = top->right;
			}
			else {
				post_order.pop();
				result.push_back(top->val);
				pre = top;
			}
		}
	}
	return result;
}