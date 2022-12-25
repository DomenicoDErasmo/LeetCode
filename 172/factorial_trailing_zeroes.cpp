#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        // return min of 2s and 5s in factors
        int twos = 0, fives = 0;
        for (int i = 2; i <= n; i++) {
            twos += getInstancesOfFactor(i, 2);
            fives += getInstancesOfFactor(i, 5);
        }
        return std::min(twos, fives);
    }
private:
    int getInstancesOfFactor(int n, int factor) {
        int result = 0;
        while (n % factor == 0) {
            result++;
            n /= factor;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
