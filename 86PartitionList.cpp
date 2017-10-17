ListNode* partition(ListNode* head, int x) {
	if (head == NULL || head->next == NULL) return head;
	ListNode *dummy = new ListNode(INT_MIN), *small, *cur;
	dummy->next = head;
	cur = dummy;
	while (cur->next != NULL && cur->next->val < x) cur = cur->next;
	if (cur->next == NULL) return head;
	small = cur;
	cur = cur->next;
	while (cur->next != NULL) {
		if (cur->next->val < x){
			ListNode *temp = cur->next;
			cur->next = temp->next;
			temp->next = small->next;
			small->next = temp;
			small = temp;
		}
		else cur = cur->next;
	}
	return dummy->next;
}