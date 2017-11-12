int helperMaxPathSum(TreeNode *root, int &max_sum) {
	if (!root) return 0;
	int l = max(0, helperMaxPathSum(root->left, max_sum));
	int r = max(0, helperMaxPathSum(root->right, max_sum));
	max_sum = max(max_sum, root->val + l + r);
	return root->val += max(l, r);
}
int maxPathSum(TreeNode* root) {
	int max_sum = INT_MIN;
	helperMaxPathSum(root, max_sum);
	return max_sum;
}