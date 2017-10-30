TreeNode * helper_sortedArrayToBST(vector<int>& nums, int start, int end) {
	if (start > end) return NULL;
	int mid = (start + end) >> 1;
	TreeNode *node = new TreeNode(nums[mid]);
	node->left = helper_sortedArrayToBST(nums, start, mid - 1);
	node->right = helper_sortedArrayToBST(nums, mid + 1, end);
	return node;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	return helper_sortedArrayToBST(nums, 0, nums.size() - 1);
}