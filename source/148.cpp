	ListNode* mergeList(ListNode *l1, int len1, ListNode *l2, int len2) {
		int l1_count = 0, l2_count = 0;
		ListNode *dummy = new ListNode(0), *cur = dummy;
		while (l1_count < len1 || l2_count < len2) {
			if (l2_count == len2 || (l1_count < len1 && l1->val < l2->val)) {
				ListNode *temp = l1->next;
				l1->next = NULL;
				cur->next = l1;
				cur = l1;
				l1 = temp;
				l1_count++;
			}
			else {
				ListNode *temp = l2->next;
				l2->next = NULL;
				cur->next = l2;
				cur = l2;
				l2 = temp;
				l2_count++;
			}
		}
		return dummy->next;
	}
	ListNode* mergeSort(ListNode *start, int len) {
		if (len == 1) return start;
		int mid = len / 2, count = 0;
		ListNode *end = start;
		while (count < mid) {
			end = end->next;
			count++;
		}
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