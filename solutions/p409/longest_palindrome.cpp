#include <iostream>
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(std::string s) {
        int frequency[128] = {0};
        for (size_t i = 0; i < s.length(); i++) {
            frequency[(int)s[i]]++;
        }
        int result = 0;
        bool any_odds = false;
        for (size_t i = 0; i < 128; i++) {
            if (frequency[i] % 2 == 0) {
                result += frequency[i];
            } else {
                result += frequency[i] - 1;
                any_odds = true;
            }
        }
        return result + (any_odds ? 1 : 0);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}