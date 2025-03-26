#include <vector>  // max, vector

class Solution {
   public:
    int maxSubArray(std::vector<int>& nums) {
        int result = nums.front(), current = nums.front();

        for (int i = 1; i < nums.size(); i++) {
            current = std::max(current + nums[i], nums[i]);
            result = std::max(current, result);
        }

        return result;
    }
};
