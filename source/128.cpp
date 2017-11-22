int longestConsecutive(vector<int>& nums) {
	if (nums.empty()) return 0;
	map<int, int> hash;
	for (auto index : nums) hash[index]++;
	int result = 0, count = 1, cur, upper, lower;
	while (!hash.empty()) {
		cur = hash.begin()->first;
		hash.erase(cur);
		upper = cur + 1;
		lower = cur - 1;
		while (hash.find(upper) != hash.end()) {
			count++;
			hash.erase(upper);
			upper++;
		}
		while (hash.find(lower) != hash.end()) {
			count++;
			hash.erase(lower);
			lower--;
		}
		result = max(result, count);
		count = 1;
	}
	return result;
}