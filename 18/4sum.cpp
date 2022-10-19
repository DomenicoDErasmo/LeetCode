#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }
	
    std::vector<std::vector<int>> kSum(std::vector<int>& nums, long long target, int start, int k) {
        std::vector<std::vector<int>> res;
        
        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }
        
        // There are k remaining values to add to the sum. The 
        // average of these values is at least target / k.
        int average_value = target / k;
        
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest 
        // value in nums is smaller than target / k.
        if (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }
            
        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                std::vector<std::vector<int>> subset = kSum(nums, target - nums[i], i + 1, k - 1);
                for (size_t j = 0; j < subset.size(); j++) {
                    std::vector<int> current_sum = {nums[i]};
                    current_sum.insert(current_sum.end(), subset[j].begin(), subset[j].end());
                    res.push_back(current_sum);
                }
            }
        }
                                            
        return res;
    }
	
    std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int target, int start) {
        std::vector<std::vector<int>> res;
        int lo = start, hi = int(nums.size()) - 1;
    
        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.push_back({ nums[lo++], nums[hi--] });
            }
        }
                                                           
        return res;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}