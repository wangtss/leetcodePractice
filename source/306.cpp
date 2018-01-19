	bool isAdditiveNumber(string num) {
		int len = num.size(), i = 0, j = 1;
		if (len < 3) return false;
		while (i < len - i) {
			if (num[0] == '0' && i > 0) break;
			long long num1 = atoi(num.substr(0, i + 1).c_str());
			j = i + 1;
			while (j - i < len - j) {
				if (num[i + 1] == '0' && j > i + 1) break;
				long long num2 = atoi(num.substr(i + 1, j - i).c_str()), sum = num1 + num2;
				if (isAdditiveNumber(num, j + 1, sum, num2)) return true;
				j++;
			}
			i++;
		}
		return false;
	}
	bool isAdditiveNumber(string num, int start, long long sum, long long pre) {
		if (start >= num.size()) return true;
		string temp = to_string(sum);
		for (int i = 1; i <= num.size() - start; ++i) {
			if (num[start] == '0' && i > 1) break;
			string cur_s = num.substr(start, i);
			if (cur_s.size() > temp.size() || cur_s.back() != temp.at(i - 1)) break;
			if (cur_s == temp) {
				long long cur = atoi(cur_s.c_str());
				return isAdditiveNumber(num, start + i, cur + pre, cur);
			}
		}
		return false;
	}