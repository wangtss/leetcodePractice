	void reorderList(ListNode* head) {
		ListNode *start = head, *end, *pre_end;
		while (start) {
			end = start;
			pre_end = start;
			while (end->next) {
				pre_end = end;
				end = end->next;
			}
			if (start == pre_end) return;
			ListNode *temp = start->next;
			start->next = end;
			end->next = temp;
			pre_end->next = NULL;
			start = temp;
		}
	}