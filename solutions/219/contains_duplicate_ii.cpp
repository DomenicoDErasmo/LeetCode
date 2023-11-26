#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        if (k == 0) {return false;}
        
        std::set<int> k_interval;
        for (size_t i = 0; i < nums.size(); i++) {
            if (k_interval.find(nums[i]) != k_interval.end()) {
                return true;
            } else if (k_interval.size() < k) {
                k_interval.insert(nums[i]);
            } else {
                k_interval.erase(nums[i - k]);
                k_interval.insert(nums[i]);
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}