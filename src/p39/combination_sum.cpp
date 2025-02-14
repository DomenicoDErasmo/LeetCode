#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                                 int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        helper(candidates, target, 0, result, current);
        return result;
    }

   private:
    void helper(std::vector<int>& candidates, int target, int index,
                std::vector<std::vector<int>>& result,
                std::vector<int>& current) {
        if (target < 0 || index == candidates.size()) {
            return;
        }

        if (target == 0) {
            result.push_back(current);
            return;
        }

        // skip
        helper(candidates, target, index + 1, result, current);

        // pick
        target -= candidates[index];
        current.push_back(candidates[index]);
        helper(candidates, target, index, result, current);

        // backtrack
        target += candidates[index];
        current.pop_back();
    }
};
