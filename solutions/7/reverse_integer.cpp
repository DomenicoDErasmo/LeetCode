#include <iostream>
#include <vector>

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        
        // push last digit onto a vector
        std::vector<long> digits;
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        
        // iterate over the vector and add digits one at a time
        for (size_t i = 0; i < digits.size(); i++) {
            result = result * 10 + digits[i];
        }
        
        // handle if the input ix negative
        if (x < 0) {
            result = -1 * result;
        }
        
        // In case our reversal is outside the 32-bit range
        if (result < INT_MIN || result >= INT_MAX) {
            result = 0;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}