void connect(TreeLinkNode *root) {
	if (!root || !root->left) return;
	TreeLinkNode *preLevel = root, *next_start = root->left, *cur;
	while (next_start) {
		while (preLevel) {
			preLevel->left->next = preLevel->right;
			cur = preLevel->right;
			preLevel = preLevel->next;
			if (preLevel) cur->next = preLevel->left;
		}
		preLevel = next_start;
		next_start = preLevel->left;
	}
}