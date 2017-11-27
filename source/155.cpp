class MinStack {
private:
	stack<int> ori_seq, min_seq;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		ori_seq.push(x);
		if (min_seq.empty() || min_seq.top() >= x) min_seq.push(x);
	}

	void pop() {
		int val = ori_seq.top();
		ori_seq.pop();
		if (val == min_seq.top()) min_seq.pop();
	}

	int top() {
		return ori_seq.top();
	}

	int getMin() {
		return min_seq.top();
	}
};