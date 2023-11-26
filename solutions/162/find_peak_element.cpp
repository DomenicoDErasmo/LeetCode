#include <iostream>
#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[mid+1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
