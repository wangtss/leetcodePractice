	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> in_order;
		while (root || !in_order.empty()) {
			if (root) {
				in_order.push(root);
				root = root->left;
			}
			else {
				root = in_order.top();
				in_order.pop();
				result.push_back(root->val);
				root = root->right;
			}
		}
		return result;
	}