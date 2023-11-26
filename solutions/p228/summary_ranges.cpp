#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if (nums.empty()) {return std::vector<std::string>();}
        
        std::vector<std::string> result;
        int first = nums[0], last = nums[0];        

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {last = nums[i];} 
            else {
                result.push_back(buildRangeString(first, last));
                first = nums[i];
                last = nums[i];
            }
        }
        result.push_back(buildRangeString(first, last));
        
        return result;
    }
private:
    std::string buildRangeString(int first, int last) {
        std::string result = std::to_string(first);
        if (first != last) {result += ("->" + std::to_string(last));}
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}