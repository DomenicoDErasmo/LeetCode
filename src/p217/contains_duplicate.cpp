#include <vector>
#include <set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> uniqueNums;
        for (int num : nums) {
            if (uniqueNums.find(num) != uniqueNums.end()) {
                return true;
            }
            uniqueNums.insert(num);
        }
        return false;
    }
};
