class NumArray {
	vector<int> tree, nums;
	int len;
public:
	NumArray(vector<int> nums) {
		this->nums = nums;
		this->len = nums.size();
		build();
	}
	void build() {
		tree.resize(2 * this->len, 0);
		for (int i = len, j = 0; j < len; ++i, ++j) {
			tree[i] = nums[j];
		}
		for (int i = len - 1; i >= 0; --i) {
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}
	}
	void update(int i, int val) {
		nums[i] = val;
		int pos = i + len;
		tree[pos] = val;
		while (pos > 0) {
			int left = pos, right = pos;
			if (pos % 2 == 0) right = pos + 1;
			else left = pos - 1;
			pos /= 2;
			tree[pos] = tree[left] + tree[right];
		}
	}

	int sumRange(int i, int j) {
		int l = i + len, r = j + len, res = 0;
		while (l <= r) {
			if (l % 2 != 0) {
				res += tree[l];
				l++;
			}
			if (r % 2 == 0) {
				res += tree[r];
				r--;
			}
			l /= 2;
			r /= 2;
		}
		return res;
	}
};