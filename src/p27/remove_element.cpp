#include <vector>

// TODO: fix
class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] == val) {
        for (int j = i + 1; j < n; j++) {
          nums[j - 1] = nums[j];
        }
        n--;
        i--;
      }
    }

    return n;
  }
};