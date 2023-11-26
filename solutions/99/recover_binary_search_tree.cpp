#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;    
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {delete left; delete right;}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        // use infix order to find the nodes to swap
        std::vector<TreeNode*> nodes = infixOrder(root);
        TreeNode *first, *second;
        for (size_t i = 0; i < nodes.size() - 1; i++) {
            bool must_swap = false;
            for (size_t j = i + 1; j < nodes.size(); j++) {
                if (nodes[i]->val > nodes[j]->val) {
                    first = nodes[i];
                    second = nodes[j];
                    must_swap = true;    
                }
            }
            if (must_swap) {
                int temp = first->val;
                first->val = second->val;
                second->val = temp;
                return;
            }
        }
    }
private:
    std::vector<TreeNode*> infixOrder(TreeNode* root) {
        std::vector<TreeNode*> result;
        TreeNode *left = root->left, *right = root->right;
        if (left) {
            std::vector<TreeNode*> left_nodes = infixOrder(left);
            result.insert(result.end(), left_nodes.begin(), left_nodes.end());
        }
        result.push_back(root);
        if (right) {
            std::vector<TreeNode*> right_nodes = infixOrder(right);
            result.insert(result.end(), right_nodes.begin(), right_nodes.end());
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}