#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::set<std::vector<int>> uniques = {std::vector<int>()};
        helper(uniques, nums, {}, 0);
        
        std::vector<std::vector<int>> result;
        for (std::set<std::vector<int>>::iterator it = uniques.begin(); it != uniques.end(); it++) {
            result.push_back(*it);
        }
        return result;
    }
private:
    void helper(std::set<std::vector<int>>& uniques, const std::vector<int>& nums, std::vector<int> base, int start) {
        for (size_t i = start; i < nums.size(); i++) {
            std::vector<int> current = base;
            current.push_back(nums[i]);
            if (uniques.find(current) == uniques.end()) uniques.insert(current);
            helper(uniques, nums, current, i + 1);
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}