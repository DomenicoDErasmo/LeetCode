#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        while (x || y) {
            if (x % 2 != y % 2) {
                result++;
            }
            x >>= 1;
            y >>= 1;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}