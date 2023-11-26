#include <iostream>
#include <set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* in_next): val(x), next(in_next) {}
    ~ListNode() {delete next;}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::set<ListNode*> visited;
        ListNode* temp = head;
        while (temp) {
            if (visited.find(temp) != visited.end()) {
                return true;
            } else {
                visited.insert(temp);
                temp = temp->next;
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}