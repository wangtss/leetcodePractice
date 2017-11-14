	void reorderList(ListNode* head) {
		if (!head) return;
		ListNode *slow = head, *fast = head;
		while (slow && fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode *right = slow->next, *pre = NULL;
		slow->next = NULL;
		while (right) {
			ListNode *temp = right->next;
			right->next = pre;
			pre = right;
			right = temp;
		}
		ListNode *left = head;
		while (left && pre) {
			ListNode *temp_left = left->next, *temp_right = pre->next;
			left->next = pre;
			pre->next = temp_left;
			left = temp_left;
			pre = temp_right;
		}
	}