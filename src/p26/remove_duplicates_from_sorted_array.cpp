#include <iostream>  // cout
#include <vector>    // vector

class Solution {
   public:
    int removeDuplicates(std::vector<int> &nums) {
        int left = 0, right = nums.size() - 1, result = nums.size() - 1;

        while (left < right) {
            if (nums[left] != nums[left + 1]) {
                left++;
                continue;
            }
            right--;
            result--;
            nums.erase(nums.begin() + (left + 1));
        }

        return result + 1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums{1, 1, 2};
    int result = solution.removeDuplicates(nums);
    if (result != 2) {
        std::cout << "Failed.\n";
    }
}