vector<int> diffWaysToCompute(string input) {
	if (input.empty()) return{};
	vector<int> res;
	for (int index = 0; index < input.size(); ++index) {
		char c = input.at(index);
		if (c == '+' || c == '-' || c == '*') {
			vector<int> left = diffWaysToCompute(input.substr(0, index));
			vector<int> right = diffWaysToCompute(input.substr(index + 1));
			for (auto l : left) {
				for (auto r : right) {
					switch (c) {
					case '+':
						res.push_back(l + r);
						break;
					case '-':
						res.push_back(l - r);
						break;
					case '*':
						res.push_back(l * r);
						break;
					}
				}
			}
		}
	}
	if (res.empty()) res.push_back(stoi(input));
	return res;
}