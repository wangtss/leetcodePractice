class BSTIterator {
public:
	stack<TreeNode*> min_node;
	BSTIterator(TreeNode *root) {
		TreeNode *iter = root;
		while (iter) {
			min_node.push(iter);
			iter = iter->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !min_node.empty();
	}

	/** @return the next smallest number */
	int next() {
		int result = min_node.top()->val;
		TreeNode *iter = min_node.top()->right;
		min_node.pop();
		while (iter) {
			min_node.push(iter);
			iter = iter->left;
		}
		return result;
	}
};