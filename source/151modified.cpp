void reverseWords(string &s) {
	int left = 0, right = 0, index = 0, count_word = 0;
	while (index < s.size()) {
		while (index < s.size() && s[index] == ' ') index++;
		if (index >= s.size()) break;
		if (count_word) s[right++] = ' ';
		left = right;
		while (index < s.size() && s[index] != ' ') s[right++] = s[index++];
		reverse(s.begin() + left, s.begin() + right);
		count_word++;
	}
	s.resize(right);
	reverse(s.begin(), s.end());
}