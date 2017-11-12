struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper_inorderTraversal(TreeNode *node, vector<int>& result) {
	if (!node) return;
	helper_inorderTraversal(node->left, result);
	result.push_back(node->val);
	helper_inorderTraversal(node->right, result);
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	helper_inorderTraversal(root, result);
	return result;
}