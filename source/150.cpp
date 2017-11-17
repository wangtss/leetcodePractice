	int evalRPN(vector<string>& tokens) {
		if (tokens.empty()) return 0;
		stack<int> operand;
		for (auto index : tokens) {
			if (index == "+" || index == "-" || index == "*" || index == "/") {
				int op1 = operand.top();
				operand.pop();
				int op2 = operand.top();
				operand.pop();
				switch (index.at(0)) {
				case '+':
					operand.push(op2 + op1);
					break;
				case '-':
					operand.push(op2 - op1);
					break;
				case '*':
					operand.push(op2 * op1);
					break;
				case '/':
					operand.push(op2 / op1);
					break;
				}
			}
			else operand.push(stoi(index));
		}
		return operand.top();
	}