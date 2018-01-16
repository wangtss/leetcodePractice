bool isAnagram(string s, string t) {
	vector<int> check(26, 0);
	for (auto c : s) {
		check[c - 'a']++;
	}
	for (auto c : t) {
		check[c - 'a']--;
	}
	for (int i = 0; i < 26; ++i) {
		if (check[i] != 0) return false;
	}
	return true;
}