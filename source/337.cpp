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