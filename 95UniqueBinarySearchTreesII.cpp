vector<TreeNode *> helper_generateTrees(int begin, int end) {
	vector<TreeNode *> result;
	if (begin > end) result.push_back(NULL);
	for (int index = begin; index <= end; ++index) {
		vector<TreeNode *> leftNode = helper_generateTrees(begin, index - 1);
		vector<TreeNode *> rightNode = helper_generateTrees(index + 1, end);
		for (auto l : leftNode) {
			for (auto r : rightNode) {
				TreeNode * root = new TreeNode(index);
				root->left = l;
				root->right = r;
				result.push_back(root);
			}
		}
	}
	return result;
}
vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode *> shit;
	if (n < 1) return shit;
	return helper_generateTrees(1, n);
}