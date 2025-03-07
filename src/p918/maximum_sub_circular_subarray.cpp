#include <limits.h>  // INT_MAX, INT_MIN

#include <vector>  // vector

class Solution {
   public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int maxKadane = INT_MIN, minKadane = INT_MAX, totalSum = 0,
            currentMax = 0, currentMin = 0;
        for (int num : nums) {
            currentMax = std::max(num, currentMax + num);
            maxKadane = std::max(maxKadane, currentMax);

            currentMin = std::min(num, currentMin + num);
            minKadane = std::min(minKadane, currentMin);

            totalSum += num;
        }

        return maxKadane < 0 ? maxKadane
                             : std::max(maxKadane, totalSum - minKadane);
    }
};
