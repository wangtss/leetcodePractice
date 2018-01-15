class MyQueue {
private:
	stack<int> in, out;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.top());
				in.pop();
			}
		}
		int res = out.top();
		out.pop();
		return res;
	}

	/** Get the front element. */
	int peek() {
		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.top());
				in.pop();
			}
		}
		int res = out.top();
		return res;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return in.empty() && out.empty();
	}
};