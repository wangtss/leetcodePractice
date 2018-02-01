	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		map<int, int> hash_nums1, hash_res;
		for (auto num : nums1) {
			hash_nums1[num]++;
		}
		for (auto num : nums2) {
			if (hash_nums1.count(num) > 0) {
				if (hash_res.count(num) == 0) {
					hash_res[num]++;
					res.push_back(num);
				}
			}
		}
		return res;
	}