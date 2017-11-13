	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return NULL;
		RandomListNode *dummy = new RandomListNode(0), *copy = dummy, *cur = head;
		vector<RandomListNode*> check_point;
		while (cur) {
			check_point.push_back(cur);
			copy->next = new RandomListNode(cur->label);
			copy->next->random = cur;
			RandomListNode *temp = cur->next;
			cur->next = copy->next;
			copy = copy->next;
			cur = temp;
		}
		copy = dummy->next;
		while (copy) {
			copy->random = copy->random->random ? copy->random->random->next : NULL;
			copy = copy->next;
		}
		cur = head;
		for (int index = 1; index < check_point.size(); ++index) {
			cur->next = check_point[index];
			cur = cur->next;
		}
		cur->next = NULL;
		return dummy->next;
	}

	
RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *newHead, *l1, *l2;
    if (head == NULL) return NULL;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
    }
        
    newHead = head->next;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        if (l1->random != NULL) l1->next->random = l1->random->next;
    }
        
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next != NULL) l2->next = l2->next->next;
    }

    return newHead;
}	