#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.length() == 0) {return {};}
        
        std::vector<std::string> result = {""};
        
        std::unordered_map<char, std::vector<char>> nums = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        
        letterCombinationsHelper(result, nums, digits, 0);
        
        return result;
    }
private:
    void letterCombinationsHelper(std::vector<std::string>& result, std::unordered_map<char, std::vector<char>>& nums, const std::string& digits, int pos) {
        if (pos >= digits.size()) {return;}
        size_t original_size = result.size();
        for (size_t i = 0; i < original_size; i++) {
            // a, b, c, ad, ae, af, bd, be, bf, cd, ce, cf
            // we delete a to insert ad ae af, then delete b to insert bd be bf, etc.
            // when we delete a, b becomes result[0], same with c when we delete b
            std::string base = result[0];
            result.erase(result.begin());
            std::vector<char> key_digits = nums[digits[pos]];
            for (size_t j = 0; j < key_digits.size(); j++) {
                result.push_back(base + key_digits[j]);
            }
        }
        letterCombinationsHelper(result, nums, digits, pos + 1);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}