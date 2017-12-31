ListNode* removeElements(ListNode* head, int val) {
	ListNode *dummy = new ListNode(0), *pre;
	dummy->next = head;
	pre = dummy;
	while (pre->next) {
		if (pre->next->val == val) {
			pre->next = pre->next->next;
		}
		else pre = pre->next;
	}
	return dummy->next;
}