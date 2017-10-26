bool helper_isSymmertric(TreeNode *p, TreeNode *q) {
	if (p == NULL && q == NULL) return true;
	else if ((p != NULL && q != NULL) && (p->val == q->val))
		return helper_isSymmertric(p->left, q->right) && helper_isSymmertric(p->right, q->left);
	return false;
}
bool isSymmetric(TreeNode* root) {
	if (root == NULL) return true;
	return helper_isSymmertric(root->left, root->right);
}