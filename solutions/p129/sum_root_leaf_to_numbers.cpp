#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
    ~TreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
private:
    int helper(TreeNode* root, int current) {
        if (!root) {return 0;} 
        
        current = 10 * current + root->val;
        if (!root->left && !root->right) {
            return current;
        } else {
            return helper(root->left, current) + helper(root->right, current);
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}