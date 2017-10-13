ListNode* deleteDuplicates(ListNode* head) {
	ListNode *pre = head, *cur = head;
	int dup = INT_MAX;
	while (cur != NULL) {
		if (cur->val == dup) {
			pre->next = cur->next;
			cur = cur->next;
		}
		else {
			pre = cur;
			dup = cur->val;
			cur = cur->next;
		}
	}
	return head;
}