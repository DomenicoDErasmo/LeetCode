#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::set<int> uniques;
        for (size_t i = 0; i < nums.size(); i++) {
            if (!uniques.count(nums[i])) {
                uniques.insert(nums[i]);
            } else {
                uniques.erase(nums[i]);
            }
        }
        return *uniques.begin();
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}