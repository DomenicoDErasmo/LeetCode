#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
    ~TreeNode() {delete left; delete right;}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::vector<int> nodes = inOrder(root);
        for (size_t i = 1; i < nodes.size(); i++) {
            if (nodes[i-1] >= nodes[i]) return false;
        }
        return true;
    }
private:
    std::vector<int> inOrder(TreeNode* root) {
        std::vector<int> result;
        TreeNode *left = root->left, *right = root->right;
        if (left) {
            std::vector<int> left_nodes = inOrder(left);
            result.insert(result.end(), left_nodes.begin(), left_nodes.end());
        }
        result.push_back(root->val);
        if (right) {
            std::vector<int> right_nodes = inOrder(right);
            result.insert(result.end(), right_nodes.begin(), right_nodes.end());
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}