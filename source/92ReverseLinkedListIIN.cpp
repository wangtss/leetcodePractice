ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (head == NULL || head->next == NULL || m == n) return head;
	ListNode *dummy = new ListNode(0), *pre, *post, *tile;
	dummy->next = head;
	pre = dummy;
	int count = 1;
	while (count != m) {
		pre = pre->next;
		count++;
	}
	tile = pre->next;
	post = pre->next;
	while (m <= n) {
		ListNode *temp = post->next;
		tile->next = post->next;
		post->next = pre->next;
		pre->next = post;
		post = temp;
		m++;
	}
	return dummy->next;
}