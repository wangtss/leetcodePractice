vector<int> plusOne(vector<int>& digits) {
	int len = digits.size(), carry = 1, sum = 0;
	for (int index = len - 1; index >= 0; --index) {
		sum = digits[index] + carry;
		digits[index] = sum % 10;
		carry = sum / 10;
	}
	if (carry) digits.insert(digits.begin(), 1, carry);
	return digits;
}