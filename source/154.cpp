int findMin(vector<int>& nums) {
	if (nums.empty()) return 0;
	int len = nums.size(), left = 0, right = len - 1, mid = 0, result = nums[0];
	while (left < right - 1) {
		mid = (left + right) >> 1;
		if (nums[left] < nums[mid]) {
			result = min(result, nums[left]);
			left = mid + 1;
		}
		else if (nums[mid] < nums[right]) {
			result = min(result, nums[mid]);
			right = mid - 1;
		}
		else left++;
	}
	result = min(result, min(nums[left], nums[right]));
	return result;
}