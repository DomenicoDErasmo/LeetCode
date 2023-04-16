#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int gaussian_sum = nums.size() * (nums.size() + 1) / 2;
        for(size_t i = 0; i < nums.size(); i++) {
            gaussian_sum -= nums[i];
        }
        return gaussian_sum;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}