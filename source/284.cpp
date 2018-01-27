class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
	int cache;
	bool ispeeked;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), ispeeked(false) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.

	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (!ispeeked) {
			ispeeked = true;
			cache = Iterator::next();
		}
		return cache;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (ispeeked) {
			ispeeked = false;
			return cache;
		}
		else return Iterator::next();
	}

	bool hasNext() const {
		if (ispeeked) return true;
		return Iterator::hasNext();
	}
};