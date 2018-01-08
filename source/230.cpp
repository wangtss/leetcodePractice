bool kthSmallest(TreeNode *node, int &k, int &res) {
	if (!node) {
		return false;
	}
	if (kthSmallest(node->left, k, res)) {
		return true;
	}
	if (k == 1) {
		res = node->val;
		return true;
	}
	k--;
	if (kthSmallest(node->right, k, res)) {
		return true;
	}
	return false;
}
int kthSmallest(TreeNode* root, int k) {
	int res = 0;
	kthSmallest(root, k, res);
	return res;
}