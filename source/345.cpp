	string reverseVowels(string s) {
		if (s.empty() || s.size() == 1) return s;
		int l = 0, r = s.size() - 1;
		map<char, bool> vowels;
		vowels['a'] = 1;
		vowels['e'] = 1;
		vowels['i'] = 1;
		vowels['o'] = 1;
		vowels['u'] = 1;
		vowels['A'] = 1;
		vowels['E'] = 1;
		vowels['I'] = 1;
		vowels['O'] = 1;
		vowels['U'] = 1;
		while (l < r) {
			while (l < r && vowels.count(s[l]) == 0) l++;
			while (l < r && vowels.count(s[r]) == 0) r--;
			if (l < r) swap(s[l++], s[r--]);
			else break;
		}
		return s;
	}