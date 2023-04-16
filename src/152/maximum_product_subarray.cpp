#include <iostream>
#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int best = INT_MIN, max_prod = 1, min_prod = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {std::swap(max_prod, min_prod);}
            max_prod = std::max(max_prod * nums[i], nums[i]);
            min_prod = std::min(min_prod * nums[i], nums[i]);
            best = std::max(best, max_prod);
        }
        return best;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
