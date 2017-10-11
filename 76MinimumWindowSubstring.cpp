string minWindow(string s, string t) {
	int lenT = t.length(), lenS = s.length(), left = 0, right = 0, lenMin = lenS + 1, counter = 0;
	map<char, int> hash;
	string result = "";
	for (int index = 0; index < lenT; ++index) hash[t.at(index)]++;
	for (; right < lenS; ++right) {
		if (hash.find(s.at(right)) != hash.end()) {
			hash[s.at(right)]--;
			if (hash[s.at(right)] >= 0) counter++;
			while (counter == lenT) {
				if (lenMin > right - left + 1) {
					lenMin = right - left + 1;
					result = s.substr(left, lenMin);
				}
				if (hash.find(s.at(left)) != hash.end()) {
					hash[s.at(left)]++;
					if (hash[s.at(left)] > 0) counter--;
				}
				left++;
			}
		}
	}
	return result;
}