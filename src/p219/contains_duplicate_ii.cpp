#include <cstdlib>        // abs
#include <unordered_set>  // unordered_set
#include <vector>         // vector

class Solution {
   public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        int left = 0;
        std::unordered_set<int> values;
        for (int right = 0; right < nums.size(); right++) {
            if (std::abs(right - left) > k) {
                values.erase(nums[left]);
                left++;
            }
            if (left != right && values.count(nums[right])) {
                return true;
            }
            values.insert(nums[right]);
        }
        return false;
    }
};
