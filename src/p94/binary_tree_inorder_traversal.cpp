#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right)
        : val(val), left(left), right(right) {}
};

class Solution {
   public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        std::vector<int> node{root->val};
        std::vector<int> left = inorderTraversal(root->left);
        std::vector<int> right = inorderTraversal(root->right);

        std::vector<int> result;
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), node.begin(), node.end());
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }
};
