bool isIsomorphic(string s, string t) {
	int count_s = 1, count_t = 1, cur_s, cur_t;
	map<char, int> hash_s, hash_t;
	for (int index = 0; index < s.length(); ++index) {
		if (hash_s.count(s.at(index)) == 0) hash_s[s.at(index)] = count_s++;
		cur_s = hash_s[s.at(index)];
		if (hash_t.count(t.at(index)) == 0) hash_t[t.at(index)] = count_t++;
		cur_t = hash_t[t.at(index)];
		if (cur_s != cur_t) return false;
	}
	return true;
}