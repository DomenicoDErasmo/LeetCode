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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* result = nullptr;
        insertNode(result, head, 0);
        ListNode *temp = head->next;

        // iterate through and insert the next element each time
        while (temp) {
            int pos = findSortedPos(result, temp->val);
            insertNode(result, temp, pos);
            temp = temp->next;
        }
        return result;
    }
private:
    int findSortedPos(ListNode* head, int val) {
        int result = 0;
        while (head && val > head->val) {
            head = head->next;
            result++;
        }
        return result;
    }
    void insertNode(ListNode*& head, ListNode *node, int pos) {
        ListNode* to_insert = new ListNode(node->val);

        if (!head || pos == 0) {
            // inserting at head
            to_insert->next = head;
            head = to_insert;
        } else {
            // inserting elsewhere in the list
            int i = 0;
            ListNode *temp = head, *prev = nullptr;
            while (i < pos) {
                prev = temp;
                temp = temp->next;
                i++;
            }
            prev->next = to_insert;
            to_insert->next = temp;
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}