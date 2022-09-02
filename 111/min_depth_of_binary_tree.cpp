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
    int minDepth(TreeNode* root) {
        return minDepthHelper(root, 1);
    }
private:
    int minDepthHelper(TreeNode* root, int level) {
        if (!root) {
            return level - 1;
        }
        if (root->left && root->right) {
            int left_depth = minDepthHelper(root->left, level + 1);
            int right_depth = minDepthHelper(root->right, level + 1);
            return left_depth < right_depth ? left_depth : right_depth;
        } else if (root->left) {
            return minDepthHelper(root->left, level + 1);
        } else if (root->right) {
            return minDepthHelper(root->right, level + 1);
        } else {
            return level;
        }
    }
};

int main() {
    std::cout << "Need to implement!" << std::endl;
    return 0;
}