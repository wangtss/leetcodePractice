TreeNode * helper_buildTreepost(vector<int>& inorder, vector<int>& postorder, int& p_pos, int i_start, int i_end) {
	if (i_start > i_end) return NULL;
	int i_pos = 0;
	for (int index = i_start; index <= i_end; ++index) {
		if (inorder[index] == postorder[p_pos]) {
			i_pos = index;
			break;
		}
	}
	TreeNode *node = new TreeNode(inorder[i_pos]);
	p_pos--;
	node->right = helper_buildTreepost(inorder, postorder, p_pos, i_pos + 1, i_end);
	node->left = helper_buildTreepost(inorder, postorder, p_pos, i_start, i_pos - 1);
	return node;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	int p_pos = postorder.size() - 1;
	return helper_buildTreepost(inorder, postorder, p_pos, 0, inorder.size() - 1);
}