#include <vector>  // vector

class Solution {
   public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        auto [right, subArraySum] = initRightAndSum(target, nums);

        if (subArraySum < target) {
            return 0;
        }

        int minSize = right, left = 0;

        while (right < nums.size()) {
            subArraySum += nums[right];
            right++;

            std::pair<int, int> leftAndSum =
                updateLeftAndSum(target, nums, left, subArraySum);
            left = leftAndSum.first;
            subArraySum = leftAndSum.second;

            minSize = std::min(minSize, right - left);
        }

        std::pair<int, int> leftAndSum =
            updateLeftAndSum(target, nums, left, subArraySum);
        left = leftAndSum.first;
        subArraySum = leftAndSum.second;

        minSize = std::min(minSize, right - left);

        return minSize;
    }

   private:
    std::pair<int, int> updateLeftAndSum(int target,
                                         const std::vector<int>& nums, int left,
                                         int subArraySum) {
        while ((subArraySum - nums[left]) >= target) {
            subArraySum -= nums[left];
            left++;
        }
        return {left, subArraySum};
    }

    std::pair<int, int> initRightAndSum(int target,
                                        const std::vector<int>& nums) {
        int right = 0, subArraySum = 0;

        while (subArraySum < target && right < nums.size()) {
            subArraySum += nums[right];
            right++;
        }

        return {right, subArraySum};
    }
};
