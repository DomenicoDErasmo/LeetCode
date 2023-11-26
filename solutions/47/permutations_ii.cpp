#include <iostream>
#include <vector>
#include <set>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<int> current;
        std::set<std::pair<std::vector<int>, std::vector<int>>> previous_subproblems;
        return helper(nums, current, previous_subproblems);
    }
    
    std::vector<std::vector<int>> helper(std::vector<int> nums, std::vector<int>& current, std::set<std::pair<std::vector<int>, std::vector<int>>>& previous_subproblems) {
        if (nums.size() == 1) {
            current.push_back(nums[0]);
            return {current};
        }
        
        std::vector<std::vector<int>> result;
        
        for (size_t i = 0; i < nums.size(); i++) {
            std::vector<int> new_current = current, new_nums = nums;
            std::swap(new_nums[0], new_nums[i]);
            new_current.push_back(new_nums[0]);
            new_nums.erase(new_nums.begin());
            
            std::pair<std::vector<int>, std::vector<int>> context = {new_nums, new_current};
            if (previous_subproblems.find(context) == previous_subproblems.end()) {
                previous_subproblems.insert(context);
                std::vector<std::vector<int>> subproblem_result = helper(new_nums, new_current, previous_subproblems);
                result.insert(result.end(), subproblem_result.begin(), subproblem_result.end());
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}