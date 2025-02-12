#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<std::vector<int>> traversal = bfs(root);
        std::vector<int> result;
        for (std::vector<int> level : traversal) {
            result.push_back(level.back());
        }
        return result;
    }

   private:
    std::vector<std::vector<int>> bfs(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::queue<std::pair<TreeNode*, int>> queue;
        std::vector<std::vector<int>> result;

        queue.push({root, 0});
        result.push_back({});

        while (!queue.empty()) {
            std::pair<TreeNode*, int> front = queue.front();
            TreeNode* currentNode = front.first;
            int currentLevel = front.second;

            if (currentLevel >= result.size()) {
                result.push_back({});
            }

            // add current node
            result[currentLevel].push_back(currentNode->val);

            // visit left child
            if (currentNode->left) {
                queue.push({currentNode->left, currentLevel + 1});
            }

            // visit right child
            if (currentNode->right) {
                queue.push({currentNode->right, currentLevel + 1});
            }

            // done with current node
            queue.pop();
        }

        return result;
    }
};
