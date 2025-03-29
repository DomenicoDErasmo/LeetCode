#include <vector>  // vector

class Solution {
   public:
    int pivotIndex(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefixSum(n, 0), suffixSum(n, 0);
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
            suffixSum[nums.size() - i - 1] =
                suffixSum[nums.size() - i] + nums[nums.size() - i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (prefixSum[i] == suffixSum[i]) {
                return i;
            }
        }
        return -1;
    }
};