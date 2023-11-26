#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result;
        
        for (size_t i = 0; i < 32; i++) {
            result = (result<<1) + (n>>i &1);
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}