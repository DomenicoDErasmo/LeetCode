#include <iostream>

class Solution {
public:
    int myAtoi(std::string s) {
        long result = 0;
        
        bool found_sign = false, is_negative = false, number_started = false;
        
        for (size_t i = 0; i < s.length(); i++) {
            if (result < INT_MIN) {
                result = INT_MIN;
                break;
            } else if (result > INT_MAX) {
                result = INT_MAX;
                break;
            } else if (!isDigit(s[i]) && !number_started) {
                if (s[i] == '-' && !found_sign) {
                    is_negative = true;
                    found_sign = true;
                    number_started = true;
                } else if (s[i] == '+' && !found_sign) {
                    is_negative = false;
                    found_sign = true;
                    number_started = true;
                } else if (s[i] == ' ') {
                    continue;
                } else {
                    break;
                }
            } else if (s[i] == ' ' && number_started) {
                break;
            } else if (isDigit(s[i])) {
                number_started = true;
                result = result * 10 + charToInt(s[i]) * (is_negative ? -1 : 1);
            } else {
                break;
            }
        }
        
        if (result < INT_MIN) {
                result = INT_MIN;
            } else if (result > INT_MAX) {
                result = INT_MAX;
        }
        
        
        return result;
    }
private:
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    
    int charToInt(char ch) {
        return ch - '0';
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}