#include <vector>  // vector

class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                // the answers are 1-indexed!
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {-1, -1};
    }
};
