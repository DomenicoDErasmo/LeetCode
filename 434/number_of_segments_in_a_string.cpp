#include <iostream>

class Solution {
public:
    int countSegments(std::string s) {
        int result = 0;
        if (s.length() == 0) {return result;}
        
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
                result++;
            }
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}