#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {return false;}
        else if (n == 1) {return true;}
        else if (n % 3) {return false;}
        else {return isPowerOfThree(n / 3);}
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}