ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode *cur_a = headA, *cur_b = headB;
	int len_a = 0, len_b = 0;
	while (cur_a) {
		cur_a = cur_a->next;
		len_a++;
	}
	while (cur_b) {
		cur_b = cur_b->next;
		len_b++;
	}
	if (!len_a || !len_b) return NULL;
	cur_a = headA;
	cur_b = headB;
	while (len_a > len_b) {
		cur_a = cur_a->next;
		len_a--;
	}
	while (len_b > len_a) {
		cur_b = cur_b->next;
		len_b--;
	}
	while (cur_a && cur_b) {
		if (cur_a == cur_b) return cur_a;
		cur_a = cur_a->next;
		cur_b = cur_b->next;
	}
	return NULL;
}