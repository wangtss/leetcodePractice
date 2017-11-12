ListNode* rotateRight(ListNode* head, int k) {
	if (head == NULL || k == 0) return head;
	int len = 1, counter = 0;
	ListNode *start = head, *end = head;
	while (end->next != NULL) {
		len++;
		end = end->next;
	}
	if (k % len == 0) return head;
	k = k % len;
	while (counter++ < len - k - 1) start = start->next;
	end->next = head;
	head = start->next;
	start->next = NULL;
	return head;
}