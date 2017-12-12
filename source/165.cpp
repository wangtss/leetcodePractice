vector<string> compareVersion(string s) {
	int count = 0, l = s.length();
	vector<string> output;
	string temp = "";
	while (count < l) {
		if (s.at(count) != '.' && !(s.at(count) == '0' && temp == "" && count + 1 < l && s.at(count + 1) != '.')) temp += s.at(count);
		if ((s.at(count) == '.' || count == l - 1) && temp != "") {
			output.push_back(temp);
			temp = "";
		}
		count++;
	}
	return output;
}
int compareVersion(string version1, string version2) {
	vector<string> v1 = compareVersion(version1), v2 = compareVersion(version2);
	int l1 = v1.size(), l2 = v2.size();
	for (int index = 0; index < max(l1, l2); ++index) {
		int a = (index < l1 ? stoi(v1[index]) : 0), b = (index < l2 ? stoi(v2[index]) : 0);
		if (a > b) return 1;
		if (a < b) return -1;
	}
	return 0;
}