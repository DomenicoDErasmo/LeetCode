#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
    ~ListNode() {delete next;}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
    ~TreeNode() {delete left; delete right;}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
private:
    TreeNode* sortedListToBST(ListNode* start, ListNode* end) {
        if (start == end) return nullptr;
        
        ListNode *mid = start, *fast = start;
        
        // need to check both becasue fast is incremented twice
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            mid = mid->next;
        }
        
        return new TreeNode (
            mid->val,
            sortedListToBST(start, mid),
            sortedListToBST(mid->next, end));
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}