from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional[ListNode] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        prev = None
        current = head
        next = head.next

        while current.next is not None:
            current.next = prev
            prev = current
            current = next  # type:ignore[assignment]
            next = next.next  # type:ignore[union-attr]

        current.next = prev

        return current


def test_p206() -> None:
    assert (
        Solution().reverseList(
            ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
        )
    ) == ListNode(5, ListNode(4, ListNode(3, ListNode(2, ListNode(1)))))


def main() -> None:
    test_p206()


if __name__ == "__main__":
    main()
