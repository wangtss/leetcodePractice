	bool increasingTriplet(vector<int>& nums) {
		int m1 = INT_MAX, m2 = INT_MAX;
		for (auto num : nums) {
			if (m1 >= num) m1 = num;
			else if (m2 >= num) m2 = num;
			else return true;
		}
		return false;
	}