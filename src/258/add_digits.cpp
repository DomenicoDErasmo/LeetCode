#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        size_t result = 0;
        
        do {
            result = 0;
            while (num > 0) {
                result += (num % 10);
                num /= 10;
            }
            num = result;
        } while (result >= 10);
        
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}