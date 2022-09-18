#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {return root;}
        TreeNode *left = root->left, *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}