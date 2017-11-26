int titleToNumber(string s) {
	if (s.empty()) return 0;
	int result = 0, len = s.size() - 1;
	for (int index = len; index >= 0; --index) {
		result += (s.at(index) - 'A' + 1) * pow(26, len - index);
	}
	return result;
}