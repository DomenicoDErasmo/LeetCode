#include <iostream>
#include <string>
#include <vector>

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
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        if (!root) {return {};}
        std::vector<std::string> paths;
        binaryTreePathsHelper(paths, root, std::to_string(root->val));
        return paths;
    }
private:
    void binaryTreePathsHelper(std::vector<std::string>& result, TreeNode* root, std::string str) {
        if (!root->left && !root->right) {
            result.push_back(str);
            return;
        }
        if (root->left) binaryTreePathsHelper(result, root->left, str + "->" + std::to_string(root->left->val));
        if (root->right) binaryTreePathsHelper(result, root->right, str + "->" + std::to_string(root->right->val));
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}