#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::sort(candidates.begin(), candidates.end());
        helper(candidates, result, current, target, 0);
        return result;
    }
private:
    void helper(const std::vector<int>& candidates, std::vector<std::vector<int>>& result, std::vector<int>& current, int target, int index) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (size_t i = index; i < candidates.size(); i++) {
            if ((i > index) && (candidates[i] == candidates[i - 1])) {continue;}
            if (candidates[i] > target) {break;}
            
            current.push_back(candidates[i]);
            helper(candidates, result, current, target - candidates[i], i + 1);
            current.pop_back();
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}