	ListNode* mergeList(ListNode *l1, int len1, ListNode *l2, int len2) {
		int l1_count = 0, l2_count = 0;
		ListNode *dummy = new ListNode(0), *cur = dummy;
		while (l1_count < len1 && l2_count < len2) {
			if (l1->val < l2->val) {
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
				l1_count++;
			}
			else {
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
				l2_count++;
			}
		}
		if (l1_count < len1) cur->next = l1;
		if (l2_count < len2) cur->next = l2;
		return dummy->next;
	}
	ListNode* mergeSort(ListNode *start, int len) {
		if (len == 1) return start;
		int mid = len / 2, count = 0;
		ListNode *end = start, *pre = NULL;
		while (count < mid) {
			pre = end;
			end = end->next;
			count++;
		}
		pre->next = NULL;
		start = mergeSort(start, mid);
		end = mergeSort(end, len - mid);
		return mergeList(start, mid, end, len - mid);
	}
	ListNode* sortList(ListNode* head) {
		if (!head) return head;
		ListNode *cur = head;
		int len = 0;
		while (cur) {
			cur = cur->next;
			len++;
		}
		return mergeSort(head, len);
	}