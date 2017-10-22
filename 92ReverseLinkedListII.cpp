ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (head == NULL || head->next == NULL || m == n) return head;
	ListNode *dummy = new ListNode(0), *pre, *post;
	dummy->next = head;
	pre = dummy;
	int count = 1;
	while (count != m) {
		pre = pre->next;
		count++;
	}
	post = pre;
	while (count++ != n) post = post->next;
	post = post->next;
	while (m != n) {
		ListNode *temp = pre->next;
		pre->next = temp->next;
		temp->next = post->next;
		post->next = temp;
		m++;
	}
	return dummy->next;
}