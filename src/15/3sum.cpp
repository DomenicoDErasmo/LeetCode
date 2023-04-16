#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        
        // from smallest to biggest
        std::sort(nums.begin(), nums.end());
        
        for (size_t i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            
            int second = i + 1, third = nums.size() - 1;
            
            // so long as the second number is less than the third number
            while (second < third) {
                int two_sum = nums[second] + nums[third];
                
                if (two_sum < target) {
                    // we need to get a bigger number
                    second++;
                } else if (two_sum > target) {
                    // we need to get a smaller number
                    third--;
                } else {
                    std::vector<int> triplet = {nums[i], nums[second], nums[third]}; 
                    result.push_back(triplet);
                    
                    // all duplicate numbers are next to each other, so simply increment/decrement second/third until we get to a new number
                    while (second < third && nums[second] == triplet[1]) {second++;}
                    while(second < third && nums[third] == triplet[2]) {third--;}
                }
            }
            
            // duplicates of the first number of the triplet
            while (i + 1 < nums.size() && nums[i+1] == nums[i]) {i++;}
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}