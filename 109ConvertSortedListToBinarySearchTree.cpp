TreeNode* helper_sortedListToBST(ListNode* head, int n) {
	if (n <= 0) return 0;
	int mid = n % 2 == 0 ? n / 2 : n / 2 + 1;
	ListNode *root = head;
	for (int index = 1; index < mid; ++index) {
		root = root->next;
	}
	TreeNode *node = new TreeNode(root->val);
	node->left = helper_sortedListToBST(head, mid - 1);
	node->right = helper_sortedListToBST(root->next, n - mid);
	return node;
}
TreeNode* sortedListToBST(ListNode* head) {
	int count = 0;
	ListNode *fake = head;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return helper_sortedListToBST(fake, count);
}