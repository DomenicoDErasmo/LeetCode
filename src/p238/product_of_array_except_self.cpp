#include <vector>  // vector

class Solution {
   public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> prefixProducts(nums.size(), 1),
            suffixProducts(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            prefixProducts[i] = prefixProducts[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            suffixProducts[i] = suffixProducts[i + 1] * nums[i + 1];
        }

        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(prefixProducts[i] * suffixProducts[i]);
        }
        return result;
    }
};
