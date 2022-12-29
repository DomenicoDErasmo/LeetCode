#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::string result;

        sort(nums);
        for (int i = 0; i < nums.size(); i++) { 
            result += std::to_string(nums[i]);
        }

        while (result.length() > 1 && result[0] == '0') {
            result.erase(result.begin());
        }
        return result;
    }
private:
    void sort(std::vector<int>& nums) const {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                std::string i_str = std::to_string(nums[i]);
                std::string j_str = std::to_string(nums[j]);
                if (i_str + j_str < j_str + i_str) {
                    std::swap(nums[i], nums[j]);
                }
            }
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}