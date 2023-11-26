#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        // two binary searches: beginning and end
        // have a variable to store the first/last occurrence of each number
        int start = 0, end = nums.size() - 1, mid;
        
        int earliest = -1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                if (nums[mid] == target) {
                    earliest = mid;
                }
                end = mid - 1;
            }
        }
        
        int latest = -1;
        start = 0, end = nums.size() - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                if (nums[mid] == target) {
                    latest = mid;
                }
                start = mid + 1;
            }
        }
        return {earliest, latest};
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}