TreeNode *pre = NULL;
void helper_flatten(TreeNode *cur) {
	if (!cur) return;
	if (pre) pre->right = cur;
	pre = cur;
	TreeNode *l = cur->left, *r = cur->right;
	cur->left = cur->right = NULL;
	helper_flatten(l);
	helper_flatten(r);
}
void flatten(TreeNode* root) {
	helper_flatten(root);
	if (pre) pre->left = pre->right = NULL;
}