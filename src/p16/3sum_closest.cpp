#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (size_t first = 0; first < nums.size(); first++) {
            size_t second = first + 1, third = nums.size() - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (abs(target - sum) < abs(target - result)) {
                    result = sum;
                } else if (sum < result) {
                    second++;
                } else {
                    third--;
                }
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}