class Solution:
    def isPalindrome(self, head):
        if head is None:
            return True
        slow = head
        fast = head
        while fast.next is not None and fast.next.next is not None:
            slow = slow.next
            fast = fast.next.next
        cur = slow.next
        slow.next = None
        while cur is not None:
            temp = cur.next
            cur.next = slow.next
            slow.next = cur
            cur = temp
        pre = head
        slow = slow.next
        while slow is not None:
            if pre.val != slow.val:
                return False
            pre = pre.next
            slow = slow.next
        return True