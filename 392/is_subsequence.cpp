#include <iostream>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.length() == 0) {return true;}
        int pos = t.find(s[0]);
        if (pos == -1) {return false;}
        return isSubsequence(s.substr(1), t.substr(pos + 1));
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}