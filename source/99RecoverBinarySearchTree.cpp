void inOrderSearch(TreeNode *root, vector<int>& inorder) {
	if (!root) return;
	inOrderSearch(root->left, inorder);
	inorder.push_back(root->val);
	inOrderSearch(root->right, inorder);
}
void assignVal(TreeNode *root, vector<int>& inorder, int& index) {
	if (root == NULL || inorder.empty()) return;
	assignVal(root->left, inorder, index);
	root->val = inorder[index++];
	assignVal(root->right, inorder, index);
}
void recoverTree(TreeNode* root) {
	vector<int> inorder;
	inOrderSearch(root, inorder);
	for (int index = 1; index < inorder.size(); ++index) {
		if (inorder[index] < inorder[index - 1]) {
			int count = index - 1, temp = inorder[index];
			inorder.erase(inorder.begin() + index);
			while (count >= 0 && temp < inorder[count]) count--;
			count++;
			inorder.insert(inorder.begin() + count, temp);
		}
	}
	int index = 0;
	assignVal(root, inorder, index);
}