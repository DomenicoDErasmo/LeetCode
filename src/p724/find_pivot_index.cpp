#include <vector>  // vector

class Solution {
   public:
    int pivotIndex(std::vector<int>& nums) {
        std::vector<int> prefixSum(nums.size(), 0);
        std::vector<int> postfixSum(nums.size(), 0);

        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i-1];
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            postfixSum[i] = postfixSum[i+1] + nums[i+1];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (prefixSum[i] == postfixSum[i]) {
                return i;
            }
        }

        return -1;
    }
};
