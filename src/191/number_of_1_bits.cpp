#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t result = 0;
        while (n) {
            if (n & 1) {
                result += 1;
            }
            n >>= 1;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}