void binaryTreePaths(TreeNode *node, string cur_path, vector<string>& res) {
	if (!node->left && !node->right) {
		res.push_back(cur_path + to_string(node->val));
		return;
	}
	cur_path += to_string(node->val) + "->";
	if (node->left) {
		binaryTreePaths(node->left, cur_path, res);
	}
	if (node->right) {
		binaryTreePaths(node->right, cur_path, res);
	}
}
vector<string> binaryTreePaths(TreeNode* root) {
	if (!root) return {};
	string cur_path;
	vector<string> res;
	binaryTreePaths(root, cur_path, res);
	return res;
}