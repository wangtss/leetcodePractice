int binarySearch(vector<int>& numbers, int left, int right, int target) {
	int mid = 0;
	if (target > numbers[right] || target < numbers[left]) return -1;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (numbers[mid] == target) return mid;
		if (numbers[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}
vector<int> twoSum(vector<int>& numbers, int target) {
	int len = numbers.size();
	for (int index = 0; index < len - 1; ++index) {
		int result = binarySearch(numbers, index + 1, len - 1, target - numbers[index]);
		if (result != -1) return { index + 1, result + 1 };
	}
}