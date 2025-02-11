#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::queue<std::pair<TreeNode *, int>> queue;
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }
        queue.push({root, 0});
        result.push_back({});

        while (!queue.empty()) {
            std::pair<TreeNode *, int> front = queue.front();
            TreeNode *currentNode = front.first;
            int currentLevel = front.second;

            if (result.size() <= currentLevel) {
                result.push_back({});
            }

            result[currentLevel].push_back(currentNode->val);
            if (currentNode->left) {
                queue.push({currentNode->left, currentLevel + 1});
            }
            if (currentNode->right) {
                queue.push({currentNode->right, currentLevel + 1});
            }

            queue.pop();
        }

        return result;
    }
};
