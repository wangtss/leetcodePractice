TreeNode * helper_buildTree(vector<int>& preorder, int& p_pos, vector<int>& inorder, int i_start, int i_end) {
	if (i_start > i_end) return NULL;
	int i_pos = 0;
	for (int index = i_start; index <= i_end; ++index) {
		if (inorder[index] == preorder[p_pos]) {
			i_pos = index;
			break;
		}
	}
	TreeNode *node = new TreeNode(inorder[i_pos]);
	p_pos++;
	node->left = helper_buildTree(preorder, p_pos, inorder, i_start, i_pos - 1);
	node->right = helper_buildTree(preorder, p_pos, inorder, i_pos + 1, i_end);
	return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int p_pos = 0;
	return helper_buildTree(preorder, p_pos, inorder, 0, inorder.size() - 1);
}