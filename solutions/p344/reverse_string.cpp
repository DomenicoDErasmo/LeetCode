#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (size_t i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
private:
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