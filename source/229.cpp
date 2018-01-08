vector<int> majorityElement(vector<int>& nums) {
	if (nums.empty()) return {};
	vector<int> res;
	int c1 = 0, c2 = 1, count1 = 0, count2 = 0;
	for (auto i : nums) {
		if (i == c1) {
			count1++;
		} 
		else if (i == c2) {
			count2++;
		}
		else if (count1 == 0) {
			c1 = i;
			count1 = 1;
		}
		else if (count2 == 0) {
			c2 = i;
			count2 = 1;
		}
		else {
			count1--;
			count2--;
		}
	}
	count1 = 0;
	count2 = 0;
	for (auto i : nums) {
		if (i == c1) {
			count1++;
		}
		else if (i == c2) {
			count2++;
		}
	}
	if (count1 > nums.size() / 3) {
		res.push_back(c1);
	}
	if (count2 > nums.size() / 3) {
		res.push_back(c2);
	}
	return res;
}