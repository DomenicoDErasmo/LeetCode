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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {return nullptr;}
        if (!head->next) {return head;}
        
        ListNode *temp = head, *new_head = temp->next, *next = temp->next, *prev = nullptr;
        // if we have an odd number of nodes, we don't want to swap the last one
        // so we check that both the current node and the next node aren't null
        while (temp && temp->next) {
            if (prev) {prev->next = next;}
            temp->next = next->next;
            next->next = temp;
            prev = temp;
            temp = temp->next;
            if (temp) {next = temp->next;}
        }
        return new_head;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
}