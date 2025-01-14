from __future__ import annotations

from typing import Optional


class ListNode:
    def toArray(self) -> list[int]:
        result = []

        temp: Optional[ListNode] = self
        while temp:
            result.append(temp.val)
            temp = temp.next

        return result

    def __str__(self):
        return str(self.toArray())

    def __init__(self, val: int = 0, next: Optional[ListNode] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:

        current: Optional[ListNode] = ListNode()
        dummy = current

        while list1 and list2:
            assert current is not None
            if list1.val < list2.val:
                current.next = list1
                list1, current = list1.next, list1
            else:
                current.next = list2
                list2, current = list2.next, list2

        if list1 or list2:
            assert current is not None
            current.next = list1 if list1 else list2

        assert dummy is not None
        return dummy.next
