int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) return 0;
	int len = nums.size(), indexNew = 1, countDup = 0, result = 1;
	for (int index = 1; index < len; ++index) {
		if (nums[index - 1] == nums[index]) {
			if (++countDup > 1) {
				
			}
			else {
				nums[indexNew++] = nums[index];
				countDup++;
				result++;
			}
		}
		else {
			nums[indexNew++] = nums[index];
			result++;
			countDup = 0;
		}
	}
	return result;
}