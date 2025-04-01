#include <algorithm>  // max
#include <optional>   // optional

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    int pairSum(ListNode *head) {
        // get mid with fast-slow
        ListNode *mid = middle(head);
        // reverse first half of linked list
        ListNode *reversedHead = reverseUpTo(head, mid);
        // use two pointers to traverse from mid to head and mid->next to end
        std::optional<int> maxSum = std::nullopt;
        while (reversedHead && mid) {
            int currentSum = mid->val + reversedHead->val;
            maxSum = maxSum.has_value() ? std::max(maxSum.value(), currentSum)
                                        : currentSum;
            reversedHead = reversedHead->next;
            mid = mid->next;
        }
        return maxSum.value_or(-1);
    }

   private:
    ListNode *middle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseUpTo(ListNode *head, ListNode *end) {
        ListNode *prev = nullptr, *current = head;
        while (current != end) {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};
