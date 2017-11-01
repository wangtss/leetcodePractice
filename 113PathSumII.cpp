void helper_pathSum(TreeNode *root, vector<int>& curPath, vector<vector<int>>& result, int sum, int localSum) {
	if (!root) return;
	localSum += root->val;
	curPath.push_back(root->val);
	if (!root->left && !root->right) {
		if (sum == localSum) result.push_back(curPath);
	}
	else {
		helper_pathSum(root->left, curPath, result, sum, localSum);
		helper_pathSum(root->right, curPath, result, sum, localSum);
	}
	curPath.pop_back();
	return;

}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> result;
	vector<int> curPath;
	helper_pathSum(root, curPath, result, sum, 0);
	return result;
}