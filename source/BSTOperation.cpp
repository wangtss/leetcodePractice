struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * creatTreeNode(int val, TreeNode *left, TreeNode *right) {
	TreeNode *newNode = new TreeNode(val);
	newNode->left = left;
	newNode->right = right;
	return newNode;
}

TreeNode * insertBST(TreeNode* node, int key) {
	if (!node) {
		node = new TreeNode(key);
		node->left = node->right = NULL;
		return node;
	}
	if (node->val > key) node->left = insertBST(node->left, key);
	else node->right = insertBST(node->right, key);
	return node;
}

bool deleteBST(TreeNode *node, int key) {
	if (!node) return false;
	else if (node->val == key) {
		if (!node->left) {
			TreeNode *temp = node;
			node = node->right;
			delete temp;
		}
		else if (!node->right) {
			TreeNode *temp = node;
			node = node->left;
			delete temp;
		}
		else {
			TreeNode *temp = node, *tempLeft = node->left;
			while (tempLeft->right) {
				temp = tempLeft;
				tempLeft = tempLeft->right;
			}
			node->val = tempLeft->val;
			if (temp != node) temp->right = tempLeft->left;
			else temp->left = tempLeft->left;
			delete tempLeft;
		}
		return true;
	}
	else if (node->val > key) return deleteBST(node->left, key);
	else return deleteBST(node->right, key);
}