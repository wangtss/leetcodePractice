class Trie {
private:
	struct TreeStructure {
		char value;
		map<char, TreeStructure*> child;
		TreeStructure(char c) : value(c) {}
	};
	TreeStructure *root;
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TreeStructure('0');
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TreeStructure *cur_node = root;
		insert(word, cur_node, 0);
	}
	void insert(string word, TreeStructure *cur_node, int index_word) {
		if (index_word == word.length()) {
			TreeStructure *end = new TreeStructure('#');
			cur_node->child['#'] = end;
			return;
		}
		char c = word.at(index_word);
		if (cur_node->child.count(c) <= 0) {
			TreeStructure *new_node = new TreeStructure(c);
			cur_node->child[c] = new_node;
		}
		cur_node = cur_node->child[c];
		index_word++;
		insert(word, cur_node, index_word);
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TreeStructure *cur_node = root;
		for (auto index : word) {
			if (cur_node->child.count(index) <= 0) return false;
			cur_node = cur_node->child[index];
		}
		return cur_node->child.count('#') > 0;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TreeStructure *cur_node = root;
		for (auto index : prefix) {
			if (cur_node->child.count(index) <= 0) return false;
			cur_node = cur_node->child[index];
		}
		return true;
	}
};