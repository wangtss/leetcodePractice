bool isPalindrome(ListNode* head) {
	if (!head) return true;
	ListNode *slow = head, *fast = head;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode *cur = slow->next, *pre = head;
	slow->next = NULL;
	while (cur) {
		ListNode *temp = cur->next;
		cur->next = slow->next;
		slow->next = cur;
		cur = temp;
	}
	slow = slow->next;
	while (slow) {
		if (pre->val != slow->val) return false;
		pre = pre->next;
		slow = slow->next;
	}
	return true;
}