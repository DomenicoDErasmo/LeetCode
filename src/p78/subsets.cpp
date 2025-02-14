#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> current = {{}};
        return helper(nums, 0, current);
    }

   private:
    std::vector<std::vector<int>> helper(
        std::vector<int>& nums, int index,
        std::vector<std::vector<int>>& current) {
        // base case: can't go anymore
        if (index == nums.size()) {
            return current;
        }

        // case where we don't pick - all of current stays the same
        std::vector<std::vector<int>> skip = helper(nums, index + 1, current);

        // case where we pick - push onto all of current
        for (int i = 0; i < current.size(); i++) {
            current[i].push_back(nums[index]);
        }
        std::vector<std::vector<int>> pick = helper(nums, index + 1, current);

        // back out backtracking
        for (int i = 0; i < current.size(); i++) {
            current[i].pop_back();
        }

        std::vector<std::vector<int>> result;
        result.insert(result.end(), skip.begin(), skip.end());
        result.insert(result.end(), pick.begin(), pick.end());

        return result;
    }
};
