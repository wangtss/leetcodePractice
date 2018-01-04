class WordDictionary {

private:
	struct wordTree {
		char val;
		map<char, wordTree*> child;
		wordTree(char c) : val(c) {}
	};
	wordTree *root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new wordTree('0');
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		insert(word, root, 0);
	}
	void insert(string word, wordTree *node, int index) {
		if (index == word.size()) {
			wordTree *end = new wordTree('#');
			node->child['#'] = end;
			return;
		}
		char c = word.at(index);
		if (node->child.count(c) <= 0) {
			wordTree *new_node = new wordTree(c);
			node->child[c] = new_node;
		}
		node = node->child[c];
		index++;
		insert(word, node, index);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(word, root, 0);
	}
	bool search(string word, wordTree *node, int index) {
		if (index == word.size()) return node->child.count('#') > 0;
		if (word.at(index) == '.') {
			for (auto sub_node : node->child) {
				if (search(word, sub_node.second, index + 1)) return true;
			}
			return false;
		}
		else return (node->child.count(word.at(index)) > 0 && search(word, node->child[word.at(index)], index + 1));
	}
};
