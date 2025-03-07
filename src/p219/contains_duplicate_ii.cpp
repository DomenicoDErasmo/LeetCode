#include <unordered_set>  // unordered_set
#include <vector>         // vector

class Solution {
   public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> valsInWindow;
        int left = 0, right = 0;
        for (int num : nums) {
            if (right - left > k) {
                valsInWindow.erase(nums[left]);
                left++;
            }
            
            right++;
            if (valsInWindow.find(num) != valsInWindow.end()) {
                return true;
            }
            valsInWindow.insert(num);
        }
        return false;
    }
};
