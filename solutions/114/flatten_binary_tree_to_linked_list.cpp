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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        // make a vector of TreeNodes, fill with a DFT
        std::vector<TreeNode*> dft;
        DFT(root, dft);
        for (size_t i = 0; i < dft.size()-1; i++) {
            dft[i]->left = nullptr;
            dft[i]->right = dft[i+1];
        }
    }
private:
    void DFT(TreeNode* root, std::vector<TreeNode*>& dft) {
        if (!root) return;
        dft.push_back(root);
        DFT(root->left, dft);
        DFT(root->right, dft);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}