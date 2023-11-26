#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {return {};}
        std::vector<int> result;
        std::stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* temp = node_stack.top(), *left = temp->left, *right = temp->right;
            node_stack.pop();
            result.push_back(temp->val);
            if (right) {node_stack.push(right);}
            if (left) {node_stack.push(left);}
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}