string addBinary(string a, string b) {
	int len_a = a.length() - 1, len_b = b.length() - 1;
	int cur_a, cur_b, carry = 0, sum = 0;
	string result, temp;
	while (len_a >= 0 || len_b >= 0 || carry != 0) {
		cur_a = len_a >= 0 ? a.at(len_a) - '0' : 0;
		cur_b = len_b >= 0 ? b.at(len_b) - '0' : 0;
		sum = cur_a + cur_b + carry;
		carry = sum / 2;
		sum = sum % 2;
		temp = sum + '0';
		result = temp + result;
		len_a--;
		len_b--;
	}
	return result;
}