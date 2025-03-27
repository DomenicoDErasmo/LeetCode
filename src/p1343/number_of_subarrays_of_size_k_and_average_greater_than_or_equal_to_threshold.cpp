#include <vector>  // vector

class Solution {
   public:
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
        int sumThreshold = k * threshold;
        int left = 0, currentSum = 0, result = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (getWindowSize(left, i) > k) {
                currentSum -= arr[left];
                left++;
            }

            currentSum += arr[i];
            if (getWindowSize(left, i) == k && currentSum >= sumThreshold) {
                result++;
            }
        }
        return result;
    }

   private:
    int getWindowSize(int left, int right) { return right - left + 1; }
};
