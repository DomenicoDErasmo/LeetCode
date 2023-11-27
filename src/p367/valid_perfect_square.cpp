#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        long low = 1, high = num;
        
        while (low <= high) {
            long guess = (low + high) / 2;
            if (guess * guess < num) {
                low = guess + 1;
            } else if (guess * guess == num) {
                return true;
            } else if (guess * guess > num) {
                high = guess - 1;
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}