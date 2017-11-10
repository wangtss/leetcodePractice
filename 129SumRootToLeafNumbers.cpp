void helper_sumNumbers(TreeNode *root, int cur, int& result) {
	if (!root) return;
	cur = cur * 10 + root->val;
	if (!root->left && !root->right) {
		result += cur;
		return;
	}
	helper_sumNumbers(root->left, cur, result);
	helper_sumNumbers(root->right, cur, result);
}
int sumNumbers(TreeNode* root) {
	int result = 0;
	helper_sumNumbers(root, 0, result);
	return result;
}