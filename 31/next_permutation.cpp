#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int i = nums.size() - 2, j = i + 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) {i--;}
        if (i == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        while(nums[j] <= nums[i]) {j--;}
        std::swap(nums[i], nums[j]);
        std::sort(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}