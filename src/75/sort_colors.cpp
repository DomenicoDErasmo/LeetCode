#include <iostream>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        onePass(nums);
    }
private:
    // LeetCode best
    void onePass(std::vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                nums[mid] = nums[low];
                nums[low] = 0;
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else if (nums[mid] == 2) {
                nums[mid] = nums[high];
                nums[high] = 2;
                high--;
            }
        }
    }

    // my fastest solution
    void countingSort(std::vector<int>& nums) {
        size_t red = 0, white = 0, blue = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            switch(nums[i]) {
                case 0:
                    red++;
                    break;
                case 1:
                    white++;
                    break;
                case 2:
                    blue++;
                    break;
                default:
                    break;
            }
        }
        size_t pos = 0;
        for (size_t i = 0; i < red; i++) {
            nums[pos] = 0;
            pos++;
        }
        for (size_t i = 0; i < white; i++) {
            nums[pos] = 1;
            pos++;
        }
        for (size_t i = 0; i < blue; i++) {
            nums[pos] = 2;
            pos++;
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}