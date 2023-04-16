#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int result = nums.size(), i = 2, two_ago = nums[0], prev = nums[1];
        while (i < result) {
            int current = nums[i];
            if ((two_ago == prev) && (prev == current)) {
                for (size_t j = i; j < nums.size() - 1; j++) {
                    std::swap(nums[j], nums[j+1]);
                }
                i--;
                result--;
            } else {
                two_ago = nums[i-1];
                prev = nums[i];
            }
            i++;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}