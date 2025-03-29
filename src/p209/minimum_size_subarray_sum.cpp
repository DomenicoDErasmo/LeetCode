#include <iostream>  // cout, endl
#include <optional>  // optional
#include <vector>    // min, vector

class Solution {
   public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0, currentSum = 0;
        std::optional<int> minLength = std::nullopt;

        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            if (currentSum < target) {
                continue;
            }

            while (currentSum - nums[left] >= target) {
                currentSum -= nums[left];
                left++;
            }
            int currentLength = i - left + 1;
            minLength = minLength.has_value()
                            ? std::min(currentLength, minLength.value())
                            : currentLength;
        }

        return minLength.value_or(0);
    }
};