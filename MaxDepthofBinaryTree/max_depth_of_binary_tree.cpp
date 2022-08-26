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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return maxDepthHelper(root, 1);
    }
private:
    int maxDepthHelper(TreeNode* root, int level) {
        if (!root->left && !root->right) {
            return level;
        }
        int left = root->left ? maxDepthHelper(root->left, level + 1) : level;
        int right = root->right ? maxDepthHelper(root->right, level + 1) : level;
        return left > right ? left : right;
    }
};

int main() {
    return 0;
}