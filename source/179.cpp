static bool comp(const string &a, const string &b) {
	return a + b > b + a;
}
string largestNumber(vector<int>& nums) {
	string result;
	vector<string> trans;
	for (auto index : nums) trans.push_back(to_string(index));
	sort(trans.begin(), trans.end(), comp);
	for (auto index : trans) result += index;
	if (result[0] == '0') return "0";
	return result;
}