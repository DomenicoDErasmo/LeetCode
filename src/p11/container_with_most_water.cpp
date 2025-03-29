#include <vector>  // max, min, vector

class Solution {
   public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;

        while (left < right) {
            maxArea = std::max(maxArea, calculateArea(height, left, right));
            if (height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return maxArea;
    }

   private:
    int calculateArea(const std::vector<int>& height, int left, int right) {
        return (right - left) * std::min(height[left], height[right]);
    }
};