#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ~ListNode() {delete next;}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) {return headA;}
        
        if (getLength(headA) > getLength(headB)) {
            return intersectionHelper(headA, headB);
        } else {
            return intersectionHelper(headB, headA);
        }
    }
private:
    ListNode* intersectionHelper(ListNode* larger, ListNode* smaller) {
        ListNode *largerTemp = larger;
        
        while (largerTemp) {
            ListNode *smallerTemp = smaller;
            while (smallerTemp) {
                if (largerTemp == smallerTemp) {
                    return largerTemp;
                }
                smallerTemp = smallerTemp->next;
            }
            largerTemp = largerTemp->next;
        }
        return nullptr;
    }
    
    int getLength(ListNode* head) {
        int result = 0;
        ListNode* temp = new ListNode();
        temp->next = head;
        
        while (temp->next) {
            result++;
            temp = temp->next;
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}