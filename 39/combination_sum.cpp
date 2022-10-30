#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        helper(candidates, target, 0, result, current);
        return result;
    }
private:
    void helper(const std::vector<int>& candidates, int target, int current_index, std::vector<std::vector<int>>& result, const std::vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
        } else if (target > 0) {
            for (size_t i = current_index; i < candidates.size(); i++) {
                if (target - candidates[i] >= 0) {
                    std::vector<int> new_current = current;
                    new_current.push_back(candidates[i]);
                    helper(candidates, target - candidates[i], i, result, new_current);
                }
            }
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}