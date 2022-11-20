#include <iostream>
#include <vector>
#include <queue>

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
    struct LevelNode {
        TreeNode* node;
        size_t level;
        LevelNode(TreeNode* node, size_t level): node(node), level(level) {}
    };
    
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        std::vector<std::vector<int>> result;
        std::queue<LevelNode> queue;
        queue.push(LevelNode(root, 0));
        while (!queue.empty()) {
            LevelNode level_node = queue.front();
            if (level_node.node->left) {
                queue.push(LevelNode(level_node.node->left, level_node.level + 1));
            }
            if (level_node.node->right) {
                queue.push(LevelNode(level_node.node->right, level_node.level + 1));
            }
            if (result.size() == level_node.level) {
                result.push_back({level_node.node->val});
            } else {
                result.back().push_back(level_node.node->val);
            }
            queue.pop();
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}