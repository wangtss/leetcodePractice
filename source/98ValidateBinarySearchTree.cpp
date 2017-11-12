bool helper_isValidBST(TreeNode *node, long long lower, long long upper) {
	if (node == NULL) return true;
	else if (node->val > lower && node->val < upper)
		return helper_isValidBST(node->left, lower, node->val) && helper_isValidBST(node->right, node->val, upper);
	return false;
}
bool isValidBST(TreeNode* root) {
	if (root == NULL) return true;
	return helper_isValidBST(root->left, LLONG_MIN, root->val) && helper_isValidBST(root->right, root->val, LLONG_MAX);
}