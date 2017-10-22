bool isLegal(string sub) {
	if (sub.size() > 3 || sub.size() < 1) return false;
	if (sub.size() > 1 && sub.at(0) == '0') return false;
	int ran = stoi(sub);
	if (ran >= 0 && ran <= 255) return true;
	return false;
}
void helper_restoreIpAddress(string& s, string& address, int begin, int countDot, vector<string>& result) {
	if (begin >= s.size()) return;
	if (countDot >= 3) {
		string sub = s.substr(begin, s.size() - begin);
		if (isLegal(sub)) result.push_back(address + sub);
		return;
	}
	for (int index = 1; index <= 3; ++index) {
		string sub = s.substr(begin, index);
		if (isLegal(sub)) {
			address += sub + ".";
			helper_restoreIpAddress(s, address, begin + index, countDot + 1, result);
			address.erase(address.size() - 1, 1);
			int index = address.size() - 1;
			while (index >= 0 && address.at(index) != '.') {
				address.erase(address.size() - 1, 1);
				index--;
			}
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	string address;
	helper_restoreIpAddress(s, address, 0, 0, result);
	return result;
}