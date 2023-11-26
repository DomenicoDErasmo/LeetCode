#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        nums = notInPlace(nums, k);
    }

private:
    std::vector<int> notInPlace(std::vector<int>& nums, int k) {
        if (nums.size() < k) { k = k % nums.size(); }
        std::vector<int> result = {nums.end() - k, nums.end()};
        result.insert(result.end(), nums.begin(), nums.end() - k);
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
