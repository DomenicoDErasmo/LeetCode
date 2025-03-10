#include <vector> // vector

class Solution {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            int right = nums.size() - 1;
            int previous = nums[0];
            bool foundSecond = false;

            for (int left = 1; left < nums.size(); left++) {
                if (nums[left] != nums[left-1]) {
                    previous = nums[left];
                    foundSecond = false;
                    continue;
                }

                if (!foundSecond) {
                    foundSecond = true;
                    continue;
                }

                nums.erase(nums.begin() + left);
                left--;
                right--;
            }

            return right + 1;
        }
};
