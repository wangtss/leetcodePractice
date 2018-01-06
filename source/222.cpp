int countNodes(TreeNode* root) {
	if (!root) return 0;
	TreeNode *node = root;
	int height = 0;
	while (node) {
		height++;
		node = node->left;
	}
	int leaf = 0;
	searchLeaf(root, leaf, height, 1);
	return (pow(2, height - 1) - 1 + leaf);
}
bool searchLeaf(TreeNode *node, int& leaf, int height, int cur_height) {
	if (!node->left && !node->right) {
		if (height == cur_height) {
			leaf++;
			return true;
		}
		else return false;
	}
	else if (!node->right) {
		leaf++;
		return false;
	}
	else return searchLeaf(node->left, leaf, height, cur_height + 1) && searchLeaf(node->right, leaf, height, cur_height + 1);
}