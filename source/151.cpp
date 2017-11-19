void reverseWords(string &s) {
	if (s.empty()) return;
	while (!s.empty() && s.at(0) == ' ') s.erase(s.begin());
	while (!s.empty() && s.at(s.length() - 1) == ' ') s.erase(s.begin() + s.length() - 1);
	if (s.empty()) return;
	char pre = s.at(0);
	for (int index = 1; index < s.size(); ++index) {
		if (pre == ' ' && s.at(index) == ' ') {
			s.erase(s.begin() + index);
			index--;
		}
		else pre = s.at(index);
	}
	int start = 0, end = s.length() - 1;
	while (start < end) {
		string left, right;
		int index_left = start, index_right = end;
		while (index_left < s.size() && s.at(index_left) != ' ') {
			left += s.at(index_left);
			index_left++;
		}
		while (index_right >= 0 && s.at(index_right) != ' ') {
			right = s.at(index_right) + right;
			index_right--;
		}
		s.replace(index_right + 1, right.size(), left);
		s.replace(index_left - left.size(), left.size(), right);
		start += right.size() + 1;
		end -= left.size() + 1;
	}
}