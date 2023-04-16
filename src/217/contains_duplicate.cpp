#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> uniques;
        for (size_t i = 0; i < nums.size(); i++) {
            if (uniques.find(nums[i]) == uniques.end()) {uniques.insert(nums[i]);}
            else {return true;}
        }
        return false;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}