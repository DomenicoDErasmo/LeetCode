#include <unordered_map>  // unordered_map
#include <vector>         // vector

class Solution {
   public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> cache;
        int currentSum = 0;
        int result = 0;

        cache[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            int sumToRemove = currentSum - k;
            if (cache.find(sumToRemove) != cache.end()) {
                result += cache[sumToRemove];
            }

            cache[currentSum]++;
        }
        return result;
    }
};
