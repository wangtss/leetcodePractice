string fractionToDecimal(int64_t numerator, int64_t denominator) {
	if (numerator == 0) return "0";
	string result;
	if (numerator < 0 ^ denominator < 0) result += "-";
	numerator = abs(numerator);
	denominator = abs(denominator);
	result += to_string(numerator / denominator);
	numerator %= denominator;
	if (!numerator) return result;
	result += ".";
	map<int, int> rem;
	while (numerator) {
		if (rem.count(numerator) > 0) {
			result.insert(rem[numerator], 1, '(');
			result += ')';
			break;
		}
		rem[numerator] = result.size();
		numerator *= 10;
		result += to_string(numerator / denominator);
		numerator %= denominator;
	}
	return result;
}