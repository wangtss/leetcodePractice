int maxProduct(vector<string>& words) {
	if (words.empty()) return 0;
	int res = 0;
	for (int i = 0; i < words.size() - 1; ++i) {
		map<char, int> hash;
		for (auto c : words[i]) hash[c]++;
		for (int j = i + 1; j < words.size(); ++j) {
			bool contain_same = false;
			if (res < words[i].size() * words[j].size()) {
				for (auto c : words[j]) {
					if (hash.count(c) > 0) {
						contain_same = true;
						break;
					}
				}
				if (!contain_same) res = words[i].size() * words[j].size();
			}
		}
	}
	return res;
}
	int maxProduct(vector<string>& words) {
		if (words.empty()) return 0;
		int res = 0;
		vector<int> hash(words.size(), 0);
		for (int i = 0; i < words.size(); ++i) {
			for (auto c : words[i]) {
				hash[i] |= 1 << (c - 'a');
			}
		}
		for (int i = 0; i < words.size() - 1; ++i) {
			for (int j = i + 1; j < words.size(); ++j) {
				if (!(hash[i] & hash[j])) res = max(res, int(words[i].size() * words[j].size()));
			}
		}
		return res;
	}