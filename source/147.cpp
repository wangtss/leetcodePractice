	ListNode* insertionSortList(ListNode* head) {
		if (!head) return NULL;
		ListNode *dummy = new ListNode(0), *sort_end = head, *unsort_start;
		dummy->next = head;
		while (sort_end->next) {
			unsort_start = sort_end->next;
			ListNode *temp = dummy;
			while (temp != sort_end) {
				if (temp->next->val > unsort_start->val) {
					sort_end->next = unsort_start->next;
					unsort_start->next = temp->next;
					temp->next = unsort_start;
					break;
				}
				temp = temp->next;
			}
			if (temp == sort_end) sort_end = sort_end->next;
		}
		return dummy->next;
	}