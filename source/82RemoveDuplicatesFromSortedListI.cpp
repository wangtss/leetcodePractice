ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode *preHead = new ListNode(INT_MAX), *cur = head, *pre;
	preHead->next = head;
	pre = preHead;
	int mark;
	while (cur != NULL) {
		if (cur->next == NULL || cur->next->val != cur->val) {
			pre = cur;
			cur = cur->next;
		}
		else {
			while (cur->next != NULL && cur->next->val == cur->val) cur = cur->next;
			cur = cur->next;
			pre->next = cur;
		}
	}
	return preHead->next;
}