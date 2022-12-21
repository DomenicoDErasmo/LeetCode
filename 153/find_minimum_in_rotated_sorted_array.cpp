#include <iostream>
#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        
        while (start < end) {
            // accounts for rotating
            if (nums[start] < nums[end]) {return nums[start];}
            
            int mid = (start + end) / 2;
            
            if (nums[mid] >= nums[start]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        
        return nums[start];
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}