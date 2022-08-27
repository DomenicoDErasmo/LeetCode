#include <cmath>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
 };
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int leftHeight = root->left ? maxHeight(root->left, 2) : 1;
        int rightHeight = root->right ? maxHeight(root->right, 2) : 1;
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        } else {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
private:
    int maxHeight(TreeNode* root, int currentLevel) {
        int leftHeight = root->left ? maxHeight(root->left, currentLevel + 1) : currentLevel;
        int rightHeight = root->right ? maxHeight(root->right, currentLevel + 1) : currentLevel;
        return leftHeight > rightHeight ? leftHeight : rightHeight;
    }
};

int main() {
    std::cout << "Must implement!" << std::endl;
    return 0;
}