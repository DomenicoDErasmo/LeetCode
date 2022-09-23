#include <iostream>
#include <vector>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        std::vector<int> frequencies;
        for (size_t i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                frequencies.push_back(i);
            }
        }
        for (size_t i = 0; i < frequencies.size() / 2; i++) {
            swap(s[frequencies[i]], s[frequencies[frequencies.size() - 1 - i]]);
        }
        return s;
    }
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    void swap(char& left, char& right) {
        char temp = left;
        left = right;
        right = temp;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}