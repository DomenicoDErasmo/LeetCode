#include <iostream>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> frequency;
        for (size_t i = 0; i < s.length(); i++) {
            if (frequency.find(s[i]) != frequency.end()) {
                frequency[s[i]]++;
            } else {
                frequency.insert({s[i], 1});
            }
        }
        
        for (size_t i = 0; i < s.length(); i++) {
            if (frequency[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}