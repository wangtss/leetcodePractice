	bool wordPattern(string pattern, string str) {
		string res_p, res_s;
		map<char, char> h_p;
		map<string, char> h_s;
		int count = 0;
		for (int i = 0; i < pattern.size(); ++i) {
			if (h_p.count(pattern.at(i)) == 0) {
				h_p[pattern[i]] = count++ - '0';
			}
			res_p += h_p[pattern[i]];
		}
		count = 0;
		int i = 0;
		while (i < str.size()) {
			string temp;
			while (i < str.size() && str[i] != ' ') {
				temp += str[i++];
			}
			if (h_s.count(temp) == 0) {
				h_s[temp] = count++ - '0';
			}
			res_s += h_s[temp];
			i++;
		}
		return res_p == res_s;
	}