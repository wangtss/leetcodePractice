bool containsNearbyDuplicate(vector<int>& nums, int k) {
	int len = nums.size();
	k = min(k, len - 1);
	map<int, int> hash;
	for (int index = 0; index < len; ++index) {
		int cur = nums[index];
		if (hash.count(cur) == 0) {
			hash[cur] = index;
		}
		else {
			int dis = index - hash[cur];
			if (dis <= k) return true;
			hash[cur] = index;
		}
	}
	return false;
}