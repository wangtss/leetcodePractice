TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root) return NULL;
	if ((p->val <= root->val && q->val >= root->val) || (p->val >= root->val && q->val <= root->val)) {
		return root;
	}
	else if (p->val > root->val && q->val > root->val) {
		return lowestCommonAncestor(root->right, p, q);
	}
	else if (p->val < root->val && q->val < root->val) {
		return lowestCommonAncestor(root->left, p, q);
	}
	else return NULL;
}