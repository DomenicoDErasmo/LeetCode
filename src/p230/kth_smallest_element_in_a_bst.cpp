#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right)
        : left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    int kthSmallest(TreeNode *root, int k) {
        std::vector<int> traversal = preOrderTraversal(root);
        return traversal[k-1];
    }

   private:
    std::vector<int> preOrderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        std::vector<int> leftVals = preOrderTraversal(root->left);
        std::vector<int> rootVal = {root->val};
        std::vector<int> rightVals = preOrderTraversal(root->right);

        std::vector<int> result;
        result.insert(result.end(), leftVals.begin(), leftVals.end());
        result.insert(result.end(), rootVal.begin(), rootVal.end());
        result.insert(result.end(), rightVals.begin(), rightVals.end());
        return result;
    }
};
