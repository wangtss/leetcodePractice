	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head, *slow = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				ListNode *det = head;
				while (det != slow) {
					det = det->next;
					slow = slow->next;
				}
				return slow;
			}
		}
		return NULL;
	}