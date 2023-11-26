#include <iostream>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {return "0";}
        std::vector<std::vector<int>> digits = productDigits(num1, num2);
        padDigits(digits);
        return digitSum(digits);
    }
private:
    int charToInt(const char& ch) {
        return ch - '0';
    }
    char intToChar(const int& n) {
        return '0' + n;
    }
    
    std::vector<std::vector<int>> productDigits(const std::string& num1, const std::string& num2) {
        std::vector<std::vector<int>> result;
        int carry = 0, last_digit;
        for (int i = num2.size() - 1; i >= 0; i--) {
            std::vector<int> zeroes(num2.size() - i - 1, 0);
            result.push_back(zeroes);
            for (int j = num1.size() - 1; j >= 0; j--) {
                int temp = charToInt(num1[j]) * charToInt(num2[i]) + carry;
                carry = temp / 10;
                last_digit = temp % 10;
                result[result.size() - 1].push_back(last_digit);
            }
            if (carry) {result[result.size() - 1].push_back(carry);}
            carry = 0;
        }
        return result;
    }
    
    void padDigits(std::vector<std::vector<int>>& digits) {
        // get max length
        int max_size = digits[0].size();
        for (size_t i = 0; i < digits.size(); i++) {
            if (digits[i].size() > max_size) {
                max_size = digits[i].size();
            }
        }
        
        // pad zeroes such that all rows are same length
        for (size_t i = 0; i < digits.size(); i++) {
            for (size_t j = digits[i].size(); j < max_size; j++) {
                digits[i].push_back(0);
            }
        }
    }
    
    std::string digitSum(const std::vector<std::vector<int>>& digits) {
        std::string result;
        int carry = 0, last_digit;
        for (size_t i = 0; i < digits[0].size(); i++) {
            int column_sum = 0;
            for (size_t j = 0; j < digits.size(); j++) {
                column_sum += digits[j][i];
            }
            column_sum += carry;
            carry = column_sum / 10;
            last_digit = column_sum % 10;
            result.insert(result.begin(), intToChar(last_digit));
        }
        if (carry) {result.insert(result.begin(), intToChar(carry));}
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}