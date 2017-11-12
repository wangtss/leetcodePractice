void combinations(string s1, string s2, int pos1, int pos2, vector<string>& result, string& cur) {
	if (pos1 == s1.size() && pos2 == s2.size()) {
		result.push_back(cur);
		return;
	}
	else if (pos1 == s1.size()) {
		result.push_back(cur + s2.substr(pos2, s2.size() - pos2 + 1));
		return;
	}
	else if (pos2 == s2.size()) {
		result.push_back(cur + s1.substr(pos1, s1.size() - pos1 + 1));
		return;
	}
	else {
		cur += s1.at(pos1);
		combinations(s1, s2, pos1 + 1, pos2, result, cur);
		cur.pop_back();
		cur += s2.at(pos2);
		combinations(s1, s2, pos1, pos2 + 1, result, cur);
		cur.pop_back();
	}
}
