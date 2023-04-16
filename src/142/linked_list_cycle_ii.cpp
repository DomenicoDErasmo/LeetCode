#include <iostream>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* result = nullptr;
        std::set<ListNode*> visited;
        ListNode *temp = head;
        while (temp) {
            if (visited.find(temp) == visited.end()) {
                visited.insert(temp);
                temp = temp->next;
            } else {
                result = temp;
                break;
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}