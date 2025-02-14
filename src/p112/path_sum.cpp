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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }

        targetSum -= root->val;

        if (!root->left && !root->right) {
            return targetSum == 0;
        }

        if (hasPathSum(root->left, targetSum)) {
            return true;
        }

        if (hasPathSum(root->right, targetSum)) {
            return true;
        }

        // not needed when we pass by value but generally done for backtracking
        targetSum += root->val;

        return false;
    }
};
