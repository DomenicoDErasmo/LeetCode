#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumHelper(root, false);
    }
private:
    int sumHelper(TreeNode* root, bool left) {
        if (!root) {return 0;}
        if (!root->left && !root->right && left) {return root->val;}
        return sumHelper(root->left, true) + sumHelper(root->right, false);
        
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}