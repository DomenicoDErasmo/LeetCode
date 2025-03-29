#include <vector>  // vector

class Solution {
   public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefixProduct(n, 1), suffixProduct(n, 1);
        for (int i = 1; i < nums.size(); i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
            suffixProduct[nums.size() - i - 1] =
                suffixProduct[nums.size() - i] * nums[nums.size() - i];
        }
        std::vector<int> result(n, 1);
        for (int i = 0; i < nums.size(); i++) {
            result[i] *= prefixProduct[i] * suffixProduct[i];
        }
        return result;
    }
};
