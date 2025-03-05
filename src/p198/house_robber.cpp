#include <unordered_map>
#include <vector>

class Solution {
   public:
    int rob(std::vector<int>& nums) { return tabulationSpaceOptimized(nums); }

   private:
   // TLE
    int recursion(std::vector<int>& nums) { return recursionHelper(nums, 0); }
    int recursionHelper(const std::vector<int>& nums, const int index) {
        if (index >= nums.size()) {
            return 0;
        }

        int pick = nums[index] + recursionHelper(nums, index + 2);
        int skip = recursionHelper(nums, index + 1);

        return std::max(pick, skip);
    }

   // TLE
    int memoization(const std::vector<int>& nums) {
        std::unordered_map<int, int> cache;
        return memoizationHelper(nums, cache, 0);
    }

    int memoizationHelper(const std::vector<int>& nums,
                          std::unordered_map<int, int>& cache,
                          const int index) {
        if (cache.find(index) != cache.end()) {
            return cache[index];
        }

        int pick = nums[index] + recursionHelper(nums, index + 2);
        int skip = recursionHelper(nums, index + 1);

        int result = std::max(pick, skip);
        cache.insert({index, result});
        return result;
    }

   // O(N) time complexity, O(N) space complexity
    int tabulation(const std::vector<int>& nums) {
        std::vector<int> subProblems(nums.size() + 1, 0);
        subProblems[0] = 0;
        subProblems[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int pick = subProblems[i-1] + nums[i];
            int skip = subProblems[i];
            subProblems[i+1] = std::max(pick, skip);
        }
        return subProblems.back();
    }

    // O(N) time complexity, O(1) space complexity
    int tabulationSpaceOptimized(const std::vector<int>& nums) {
        int twoAgo = 0, oneAgo = 0, result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int pick = twoAgo + nums[i];
            int skip = oneAgo;
            result = std::max(pick, skip);

            twoAgo = oneAgo;
            oneAgo = result;
        }
        return result;
    }
};
