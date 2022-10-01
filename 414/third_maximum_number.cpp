#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::set<int> unique_nums;
        std::vector<int> vec;
        for (size_t i = 0; i < nums.size(); i++) {
            if (unique_nums.find(nums[i]) == unique_nums.end()) {
                unique_nums.insert(nums[i]);
                vec.push_back(nums[i]);
            }
        }
        std::sort(vec.begin(), vec.end());
        if (vec.size() >= 3) {
            return vec[vec.size() - 3];
        } else {
            return vec[vec.size() - 1];
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    std::vector<int> test_case = {3, 2, 1};
    Solution solution;
    std::cout << "Solution: " << solution.thirdMax(test_case) << std::endl;
    return 0;
}