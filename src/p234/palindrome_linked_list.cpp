#include <iostream>
#include <vector>

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
    bool isPalindrome(ListNode* head) {
        std::vector<int> vec = listToVector(head);
        for (size_t i = 0; i < vec.size() / 2; i++) {
            if (vec[i] != vec[vec.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
private:
    std::vector<int> listToVector(ListNode* head) {
        std::vector<int> result;
        
        ListNode* temp = head;
        while (temp) {
            result.push_back(temp->val);
            temp = temp->next;
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}