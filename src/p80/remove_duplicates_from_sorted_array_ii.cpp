#include <unordered_map>  // unordereunordered_mapd_set
#include <vector>         // vector

class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        std::unordered_map<int, int> count;
        int left = 0, right = nums.size();

        while (left < right) {
            count[nums[left]]++;

            if (count[nums[left]] <= 2) {
                left++;
                continue;
            }

            count[nums[left]]--;
            nums.erase(nums.begin() + left);
            right--;
        }

        return right;
    }
};