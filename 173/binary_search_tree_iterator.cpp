#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): 
        val(x), left(left), right(right) {}
    ~TreeNode() {delete left; delete right;}
};

class BSTIterator {
public:
    // using inorder - stack!
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = nodes.top();
        nodes.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
private:
    std::stack<TreeNode*> nodes;
    
    void pushAll(TreeNode* root) {
        for (TreeNode* node = root; node != nullptr; node = node->left) {
            nodes.push(node);
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
