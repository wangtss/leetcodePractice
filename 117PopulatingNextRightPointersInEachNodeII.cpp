void connect(TreeLinkNode *root) {
	if (!root || (!root->left && !root->right)) return;
	TreeLinkNode *preLevel = root, *next_start = root, *cur;
	while (next_start) {
		preLevel = next_start;
		while (preLevel) {
			if (preLevel->left && preLevel->right) {
				preLevel->left->next = preLevel->right;
				cur = preLevel->right;
			}
			else if (!preLevel->left) cur = preLevel->right;
			else cur = preLevel->left;
			preLevel = preLevel->next;
			while (preLevel && !preLevel->left && !preLevel->right) preLevel = preLevel->next;
			if (preLevel) cur->next = preLevel->left ? preLevel->left : preLevel->right;
		}
		cur = next_start->left ? next_start->left : next_start->right;
		while (cur && !cur->left && !cur->right) cur = cur->next;
		next_start = cur;
	}
}