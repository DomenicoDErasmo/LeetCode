#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int water = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int h = std::min(height[i], height[j]);
            water = std::max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}