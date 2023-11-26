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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {return false;}
        if (isLeafNode(root)) {return root->val == targetSum;}
        bool left_is_path_sum = root->left ? hasPathSum(root->left, targetSum - root->val) : false;
        bool right_is_path_sum = root->right ? hasPathSum(root->right, targetSum - root->val) : false;
        return left_is_path_sum || right_is_path_sum;
    }
private:
    bool isLeafNode(TreeNode* root) {return !root->left && !root->right;}
};

int main() {
    std::cout << "Need to implement!" << std::endl;
    return 0;
}