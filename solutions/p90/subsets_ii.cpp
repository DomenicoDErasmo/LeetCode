#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        helper(result, nums, current, 0);
        return result;
    }
private:
    void helper(std::vector<std::vector<int>>& result, const std::vector<int>& nums, std::vector<int>& current, int start) {
        result.push_back(current);
        for (size_t i = start; i < nums.size(); i++) {
            if (i == start || nums[i] != nums[i - 1]) {
                current.push_back(nums[i]);
                helper(result, nums, current, i+1);
                current.pop_back();
            }
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}