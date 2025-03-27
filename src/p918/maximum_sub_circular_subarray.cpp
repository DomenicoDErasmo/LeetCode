#include <limits.h>  // INT_MIN, INT_MAX

#include <vector>  // max, min, vector

class Solution {
   public:
    long maxSubarraySumCircular(std::vector<int>& nums) {
        long largest = INT_MIN, smallest = INT_MAX, currentLargest = INT_MIN,
             currentSmallest = INT_MAX, totalSum = 0;
        for (long num : nums) {
            currentLargest = std::max(currentLargest + num, num);
            currentSmallest = std::min(currentSmallest + num, num);
            largest = std::max(currentLargest, largest);
            smallest = std::min(currentSmallest, smallest);
            totalSum += num;
        }
        return largest < 0 ? largest : std::max(largest, totalSum - smallest);
    }
};
