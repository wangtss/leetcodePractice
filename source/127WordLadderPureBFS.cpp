int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	int min_step = 1, flag = 0;
	queue<string> border;
	border.push(beginWord);
	map<string, int> hash_table;
	for (auto index : wordList) hash_table[index]++;
	while (!border.empty()) {
		int count = border.size();
		for (int index = 0; index < count; ++index) {
			string temp = border.front(), shit;
			border.pop();
			if (temp == endWord) return min_step;
			for (int index_letter = 0; index_letter < temp.size(); ++index_letter) {
				for (int index_order = 0; index_order < 26; ++index_order) {
					shit = temp;
					shit[index_letter] = 'a' + index_order;
					if (hash_table.find(shit) != hash_table.end() && hash_table[shit]) {
						border.push(shit);
						hash_table[shit]--;
					}
				}
			}
		}
		min_step++;
	}
	return 0;
}