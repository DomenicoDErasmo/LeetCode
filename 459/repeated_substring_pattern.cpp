#include <iostream>
#include <vector>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        // get all factors of the string
        // for all those, check if all substrings
        std::vector<int> factors = getAllFactors(s.length());
        
        for (size_t i = 0; i < factors.size(); i++) {
            bool perfect_repeat = true;
            std::string substring = s.substr(0, factors[i]);
            for (size_t j = 0; j < s.length() / factors[i]; j++) {
                if (s.substr(factors[i] * j, factors[i]) != substring) {
                    perfect_repeat = false;
                    break;
                }
            }
            if (perfect_repeat) {
                return true;
            }
        }
        return false;
    }
private:
    std::vector<int> getAllFactors(int n) {
        std::vector<int> result;
        for (size_t i = 1; i <= n / 2; i++) {
            if (!(n % i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}