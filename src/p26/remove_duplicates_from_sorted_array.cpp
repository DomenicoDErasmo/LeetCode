#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int current_nums = 1;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        nums[current_nums] = nums[i];
        current_nums++;
      }
    }

    return current_nums;
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