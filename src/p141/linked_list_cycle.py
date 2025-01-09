from __future__ import annotations
from typing import Optional

class ListNode:
    def __init__(self, x: int, node: Optional[ListNode]) -> None:
        self.val = x
        self.next = node


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # edge cases for fast pointer
        if not head or not head.next or not head.next.next:
            return False
        
        fast = head
        slow = head

        while slow.next and fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                return True

        return False

# this one is awkward to test
