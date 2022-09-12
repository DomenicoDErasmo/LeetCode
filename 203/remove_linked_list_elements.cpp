#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
    ~ListNode() {delete next;}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(nullptr == head) {return head;}

        head->next = removeElements(head->next,val);
        return head->val == val ? head->next : head;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}