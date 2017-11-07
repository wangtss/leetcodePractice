bool isAlphaNum(char &ch) {
	if (ch >= 'a' && ch <= 'z') return true;
	if (ch >= 'A' && ch <= 'Z') {
		ch += 32;
		return true;
	}
	if (ch >= '0' && ch <= '9') return true;
	return false;
}
bool isPalindrome(string s) {
	if (s.empty()) return true;
	int start = 0, end = s.size() - 1;
	while (start < end) {
		while (start < s.size() && !isAlphaNum(s.at(start))) start++;
		while (end >= 0 && !isAlphaNum(s.at(end))) end--;
		if (start < end) {
			if (s.at(start) != s.at(end)) return false;
			start++;
			end--;
		}
	}
	return true;
}