#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {return head;}

        ListNode *temp = nullptr, *slow = head, *fast = head;

        // get middle
        while (fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return mergeList(l1, l2);
    }
private:
    ListNode* mergeList(ListNode*& l1, ListNode*& l2) {
        ListNode *result = new ListNode(0, nullptr), *current = result;
        while (l1 && l2) {
            ListNode** chosen = l1->val < l2->val ? &l1 : &l2;
            current->next = *chosen;
            *chosen = (*chosen)->next;
            current = current->next;
        }
        current->next = l1 ? l1 : l2;
        return result->next;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}