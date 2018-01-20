class NumArray {
	vector<int> tree;
	vector<int> arry;
	int len;
public:
	int lowbit(int pos) {
		return pos & (-pos);
	}
	void add(int pos, int value) {
		for (; pos <= len; pos += lowbit(pos)) {
			tree[pos] += value;
		}
	}
	int getsum(int pos) {
		int res = 0;
		for (; pos > 0; pos -= lowbit(pos)) {
			res += tree[pos];
		}
		return res;
	}
	NumArray(vector<int> nums) {
		len = nums.size();
		tree.resize(len + 1, 0);
		arry = nums;
		for (int i = 0; i < len; ++i) {
			add(i + 1, arry[i]);
		}
	}

	void update(int i, int val) {
		int delta = val - arry[i];
		arry[i] = val;
		add(i + 1, delta);
	}

	int sumRange(int i, int j) {
		return getsum(j + 1) - getsum(i);
	}
};