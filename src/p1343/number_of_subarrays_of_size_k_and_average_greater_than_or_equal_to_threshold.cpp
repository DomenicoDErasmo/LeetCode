#include <vector>  // vector

class Solution {
   public:
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
        if (arr.size() < k) {
            return 0;
        }

        int left = 0, target = threshold * k, sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int result = (sum >= target);
        for (int i = k; i < arr.size(); i++) {
            sum -= arr[left];
            left++;
            sum += arr[i];
            if (sum >= target) {
                result++;
            }
        }
        return result;
    }
};
