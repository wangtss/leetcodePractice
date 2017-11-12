TreeNode *pos1 = NULL, *pos2 = NULL, *pre = NULL;
void helper_recoverTree(TreeNode *root) {
	if (root == NULL) return;
	helper_recoverTree(root->left);
	if (pre != NULL && pre->val > root->val) {
		if (pos1 == NULL && pos2 == NULL) {
			pos1 = pre;
			pos2 = root;
		}
		else pos2 = root;
	}
	pre = root;
	helper_recoverTree(root->right);
}
void recoverTree(TreeNode* root) {
	helper_recoverTree(root);
	if (pos1 != NULL && pos2 != NULL) swap(pos1->val, pos2->val);
}