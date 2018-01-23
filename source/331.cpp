	bool isValidSerialization(string preorder) {
		if (preorder == "#") return true;
		stack<char> tree;
		int len = preorder.size(), i = 0;
		while (i < len) {
			string temp;
			while (i < len && preorder.at(i) != ',') temp += preorder.at(i++);
			if (temp != "#") tree.push('0');
			else {
				if (tree.empty()) return false;
				char top = tree.top();
				while (tree.size() >= 2 && top == '#') {
					tree.pop();
					if (tree.top() == '#') return false;
					tree.pop();
					if (!tree.empty()) top = tree.top();
				}
				tree.push('#');
			}
			i++;
		}
		if (tree.size() == 1 && tree.top() == '#') return true;
		return false;
	}