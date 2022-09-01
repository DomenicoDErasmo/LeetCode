#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        parseInput(s);
        if (s.length() <= 1) {return true;}
        for (size_t i = 0; i <= s.length() / 2; i++) {
            if (s[i] != s[s.length() - i - 1]) {return false;}
        }
        return true;
    }
private:
    void makeLowercase(char& ch) {ch = char((int)ch + 32);}
    
    bool isLowercase(char ch) {return ('a' <= ch && ch <= 'z');}
    
    bool isNumber(char ch) {return '0' <= ch && ch <= '9';}
    
    bool isUppercase(char ch) {return ('A' <= ch && ch <= 'Z');}
    
    void parseInput(std::string& s) {
        for (size_t i = 0; i < s.length(); i++) {
            if (isLowercase(s[i]) || isNumber(s[i])) {
                continue;
            } else if (isUppercase(s[i])) {
                makeLowercase(s[i]);
            } else {
                s.erase(i, 1);
                i--;
            }
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}