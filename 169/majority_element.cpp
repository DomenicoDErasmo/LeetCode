#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        
        std::unordered_map<int, int> frequencies;
        for (size_t i = 0; i < nums.size(); i++) {
            if (frequencies.find(nums[i]) == frequencies.end()) {
                frequencies.insert({nums[i], 1});
            } else {
                frequencies[nums[i]]++;
                std::cout << frequencies[nums[i]] << std::endl;
                if (frequencies[nums[i]] > nums.size() / 2) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}