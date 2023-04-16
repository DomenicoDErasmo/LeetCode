#include <iostream>
#include <vector>

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
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> result;
        helper(root, targetSum, result, std::vector<int>());
        return result;
    }
private:
    void helper(TreeNode* root, int targetSum, std::vector<std::vector<int>>& result, std::vector<int> current) {
        if (!root) return;
        targetSum = targetSum - root->val;
        current.push_back(root->val);
        TreeNode *left = root->left, *right = root->right;
        if (!left && !right && !targetSum) {
            result.push_back(current);
            return;
        }
        helper(left, targetSum, result, current);
        helper(right, targetSum, result, current);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}