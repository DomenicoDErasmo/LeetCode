#include <iostream>

class Solution {
public:
    int arrangeCoins(int n) {
        int result = 1;
        while (n >= result) {
            n -= result;
            result++;
        }
        return result - 1;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}