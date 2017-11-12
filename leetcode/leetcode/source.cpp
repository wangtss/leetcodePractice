#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solutions {
private:
	int ID;
public:
	Solutions(int x) : ID(x) {}
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int index_bit = 0; index_bit < 32; ++index_bit) {
			int sum = 0;
			for (int index_nums = 0; index_nums < nums.size(); ++index_nums) {
				sum += (nums[index_nums] >> index_bit) & 1;
			}
			result |= (sum % 3) << index_bit;
		}
		return result;
	}
};

int main() {
	Solutions demo(131);
	vector<int> shit = { 2, 2, 2, 1 };
	auto result = demo.singleNumber(shit);
	return 0;
}