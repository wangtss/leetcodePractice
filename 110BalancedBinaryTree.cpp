bool helper_isBalanced(TreeNode *root, int& height) {
	if (root == NULL) {
		height = 0;
		return true;
	}
	int h_left = 0, h_right = 0;
	if (helper_isBalanced(root->left, h_left) && helper_isBalanced(root->right, h_right)) {
		height = max(h_left, h_right) + 1;
		if (abs(h_left - h_right) < 2) return true;
	}
	return false;
}
bool isBalanced(TreeNode* root) {
	int height = 0;
	return helper_isBalanced(root, height);
}