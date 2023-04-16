#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> prev_nums;
        return isHappyHelper(n, prev_nums);
    }
private:
    bool isHappyHelper(int n, std::unordered_set<int>& prev_nums) {
        std::vector<int> digits = digitsFromInt(n);
        int sum_of_digit_squares = sumOfDigitSquares(digits);
        if (sum_of_digit_squares == 1) {
            return true;
        } else if (prev_nums.find(sum_of_digit_squares) != prev_nums.end()) {
            return false;
        } else {
            prev_nums.insert(sum_of_digit_squares);
            return isHappyHelper(sum_of_digit_squares, prev_nums);
        }
    }
    
    std::vector<int> digitsFromInt(int n) {
        std::vector<int>result;
        while (n) {
            result.push_back(n % 10);
            n /= 10;
        }
        return result;
    }
    int sumOfDigitSquares(const std::vector<int>& digits) {
        int result = 0;
        for (size_t i = 0; i < digits.size(); i++) {
            result += digits[i] * digits[i];
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}