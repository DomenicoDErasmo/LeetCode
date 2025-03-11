#include <vector>  // vector

class Solution {
   public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = height.size() - 1, max = 0;
        bool updateLeft = true;
        while (left < right) {
            int current =
                std::min(height[left], height[right]) * (right - left);
            max = std::max(max, current);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }
};
