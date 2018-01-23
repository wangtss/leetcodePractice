	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next || !head->next->next) return head;
		ListNode *odd = new ListNode(0), *even = new ListNode(0);
		odd->next = head;
		odd = odd->next;
		even->next = head->next;
		ListNode *cur_even = head->next;
		while (odd->next &&odd->next->next) {
			odd->next = odd->next->next;
			odd = odd->next;
			if (odd->next) {
				cur_even->next = odd->next;
				cur_even = cur_even->next;
			}
		}
		cur_even->next = NULL;
		odd->next = even->next;
		return head;
	}