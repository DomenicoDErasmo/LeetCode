#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
    ~ListNode() {delete next;}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0), *before_temp = before, *after = new ListNode(0), *after_temp = after;
        
        ListNode *temp = head;
        while (temp) {
            if (temp->val < x) {
                before_temp->next = temp;
                before_temp = before_temp->next;
            } else {
                after_temp->next = temp;
                after_temp = after_temp->next;
            }
            temp = temp->next;
        }
        
        before_temp->next = after->next;
        after_temp->next = nullptr;
        return before->next;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}