bool isOneDifferent(string s1, string s2) {
	int count = 0, index = 0, len = s1.size();
	while (index < len && count <= 1) {
		if (s1.at(index) != s2.at(index)) count++;
		index++;
	}
	if (count > 1) return false;
	return true;
}
void helperLadderLength(string beginWord, string endWord, vector<string>& wordList, int& min_step, int cur_step) {
	if (beginWord == endWord) {
		min_step = (cur_step < min_step || min_step == 0) ? cur_step : min_step;
		return;
	}
	if (wordList.empty()) return;
	auto copy = wordList;
	int count = 0;
	for (auto index : wordList) {
		if (isOneDifferent(beginWord, index)) {
			copy.erase(copy.begin() + count);
			helperLadderLength(index, endWord, copy, min_step, cur_step + 1);
			copy = wordList;
		}
		count++;
	}
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	int min_step = 0;
	helperLadderLength(beginWord, endWord, wordList, min_step, 1);
	return min_step;
}