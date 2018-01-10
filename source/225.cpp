class MyStack {
private:
	queue<int> in, out;
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		in.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int len = in.size();
		queue<int> temp;
		for (int index = 0; index < len - 1; ++index) {
			temp.push(in.front());
			in.pop();
		}
		int f = in.front();
		in = temp;
		return f;
	}

	/** Get the top element. */
	int top() {
		int len = in.size();
		queue<int> temp = in;
		for (int index = 0; index < len - 1; ++index) {
			temp.pop();
		}
		return temp.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return in.empty();
	}
};