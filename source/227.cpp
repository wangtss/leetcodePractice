void calculate(stack<char>& op, stack<int>& num) {
	char c = op.top();
	op.pop();
	int a = num.top();
	num.pop();
	int b = num.top();
	num.pop();
	switch (c) {
	case '+':
		num.push(b + a);
		break;
	case '-':
		num.push(b - a);
		break;
	case '*':
		num.push(b * a);
		break;
	case '/':
		num.push(b / a);
		break;
	}
}
int calculate(string s) {
	map<char, int> prior;
	prior['+'] = 1;
	prior['-'] = 1;
	prior['*'] = 2;
	prior['/'] = 2;
	stack<char> op;
	stack<int> num;
	int index = 0;
	while (index < s.size()) {
		if (s[index] >= '0' && s[index] <= '9') {
			string temp;
			while (index < s.size() && s[index] >= '0' && s[index] <= '9') temp += s[index++];
			num.push(stoi(temp));
		}
		else {
			if (s[index] != ' ') {
				while (!op.empty() && prior[s[index]] <= prior[op.top()]) calculate(op, num);
				op.push(s[index]);
			}
			index++;
		}
	}
	while (!op.empty()) {
		calculate(op, num);
	}
	return num.top();
}