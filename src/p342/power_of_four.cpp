#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) {return false;}
        else if (n == 1) {return true;}
        else if (n % 4) {return false;}
        else {return isPowerOfFour(n/4);}
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}