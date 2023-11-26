#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            int pos = abs(nums[i]) - 1;
            nums[pos] = -abs(nums[pos]);
        }
        
        std::vector<int> result;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}