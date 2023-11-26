#include <iostream>
#include <vector>
#include <unordered_map>

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
    std::vector<int> findMode(TreeNode* root) {
        std::vector<int> result;
        
        // build frequency list
        std::unordered_map<int, int> frequencies;
        buildFrequencies(root, frequencies);
        
        // get max frequency
        int max_frequency = 0;
        for (std::unordered_map<int, int>::iterator iter = frequencies.begin(); iter != frequencies.end(); iter++) {
            if (iter->second > max_frequency) {
                max_frequency = iter->second;
            }
        }
        
        // push all values with frequencies equal to max frequency
        for (std::unordered_map<int, int>::iterator iter = frequencies.begin(); iter != frequencies.end(); iter++) {
            if (iter->second == max_frequency) {
                result.push_back(iter->first);
            }   
        }
        
        return result;
    }
private:
    void buildFrequencies(TreeNode* root, std::unordered_map<int, int>& frequencies) {
        if (!root) {return;}
        if (frequencies.find(root->val) == frequencies.end()) {
            frequencies.insert({root->val, 1});
        } else {
            frequencies[root->val]++;
        }
        buildFrequencies(root->left, frequencies);
        buildFrequencies(root->right, frequencies);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}