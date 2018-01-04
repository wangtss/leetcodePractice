    def reverseList(self, head):
        dummy = ListNode(0)
        cur = head
        while cur:
            temp = cur.next
            cur.next = dummy.next
            dummy.next = cur
            cur = temp
        return dummy.next