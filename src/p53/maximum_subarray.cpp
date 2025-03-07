#include <vector> // vector

class Solution {
    public:
        int maxSubArray(std::vector<int>&  nums) {
            int maxSum = nums[0], curSum = 0;
            for (int num : nums) {
                curSum = std::max(curSum, 0);
                curSum += num;
                maxSum = std::max(maxSum, curSum);
            }
            return maxSum;
        }
};
