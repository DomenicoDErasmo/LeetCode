#include <iostream>
#include <set>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        
        // traverse once over list and get list of duplicates
        std::set<int> duplicates;
        ListNode* temp = head;
        while (temp->next) {
            if (temp->val == temp->next->val && duplicates.find(temp->val) == duplicates.end()) {
                duplicates.insert(temp->val);
            }
            temp = temp->next;
        }
        
        // first get the head
        while (head && duplicates.find(head->val) != duplicates.end()) {
            head = head->next;
        }
        
        if (!head) return head;
        
        // next, iterate over and set next node = first node whose val not in set
        ListNode *prev = head;
        temp = head->next;
        while (temp) {
            while (temp && (duplicates.find(temp->val) != duplicates.end())) {
                temp = temp->next;
            }
            prev->next = temp;
            prev = temp;
            if (temp) {
                temp = temp->next;
            }
        }
        
        return head;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}