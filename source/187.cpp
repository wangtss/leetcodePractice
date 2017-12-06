vector<string> findRepeatedDnaSequences(string s) {
	vector<string> rep;
	int l = s.length();
	if (l == 0) return rep;
	map<string, int> hash;
	for (int index = 9; index < l; ++index) {
		string seq = s.substr(index - 9, 10);
		if (hash.count(seq) > 0) {
			if (hash[seq] == 1) rep.push_back(seq);
		}
		hash[seq]++;
	}
	return rep;
}