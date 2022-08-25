#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int in_val): val(in_val), left(nullptr), right(nullptr) {}
    TreeNode(int in_val, TreeNode* in_left, TreeNode* in_right): val(in_val), left(in_left), right(in_right) {}
    ~TreeNode() {
        if (left) {delete left;}
        if (right) {delete right;}
    }
};

class Solution {
public:
    bool helper(TreeNode* node1,TreeNode* node2){
        if(!node1 && !node2)
            return true;
        if(!node1 || !node2)
            return false;
        if(node1->val != node2->val)
            return false;
        return helper(node1->left,node2->right) && helper(node1->right,node2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return helper(root->left,root->right);
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4), nullptr));
    std::string result = solution.isSymmetric(root) ? "true" : "false";
    std::cout << "Result: " << result << std::endl;
    return 0;
}
