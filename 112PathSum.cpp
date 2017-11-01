bool helper_hasPathSum(TreeNode *root, int sum, int localSum) {
	if (!root) return false;
	if (!root->left && !root->right) return sum == localSum + root->val;
	return (helper_hasPathSum(root->left, sum, localSum + root->val) || helper_hasPathSum(root->right, sum, localSum + root->val));
}
bool hasPathSum(TreeNode* root, int sum) {
	return helper_hasPathSum(root, sum, 0);
}