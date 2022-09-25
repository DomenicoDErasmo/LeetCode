#include <iostream>

int guess(int num) {
    // Example definition so this compiles
    // The real implementation of this might fetch a value from a config file and then compare the guess to that.
    if (num < 4) {
        return -1;
    } else if (num > 4) {
        return 1;
    } else {
        return 0;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        size_t low = 1, high = n;
        while(low <= high) {
            size_t mid = (low + high) / 2;
            if (guess(mid) == -1) {
                high = mid - 1;
            } else if (guess(mid) == 1) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}