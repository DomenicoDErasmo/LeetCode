#include <iostream>
#include <vector>

class NumArray {
public:
    NumArray(std::vector<int>& nums) {
        nums_arr = new int[nums.size()];
        for (size_t i = 0; i < nums.size(); i++) {
            nums_arr[i] = nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; i++) {
            result += nums_arr[i];
        }
        return result;
    }
private:
    int* nums_arr;
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}