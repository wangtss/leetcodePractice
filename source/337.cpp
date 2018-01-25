	int rob(TreeNode* root) {
		map<TreeNode*, int> hash;
		return rob(root, hash);
	}
	int rob(TreeNode *node, map<TreeNode*, int>& hash) {
		if (!node) return 0;
		if (hash.count(node)) return hash[node];
		int val = 0;
		if (node->left) val += rob(node->left->left, hash) + rob(node->left->right, hash);
		if (node->right) val += rob(node->right->left, hash) + rob(node->right->right, hash);
		val = max(val + node->val, rob(node->left, hash) + rob(node->right, hash));
		hash[node] = val;
		return val;
	}
	int rob(TreeNode* root) {
		vector<int> res = dfs(root);
		return max(res[0], res[1]);
	}
	vector<int> dfs(TreeNode *node) {
		if (!node) return { 0, 0 };
		vector<int> left = dfs(node->left), right = dfs(node->right), res(2, 0);
		res[0] = max(left[0], left[1]) + max(right[0], right[1]);
		res[1] = left[0] + right[0] + node->val;
		return res;
	}