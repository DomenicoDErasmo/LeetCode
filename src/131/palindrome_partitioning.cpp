#include <iostream>
#include <vector>
#include <string>

class Solution {
 public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> current;
        helper(s, &result, &current, 0, s.length());
        return result;
    }

 private:
    void helper(std::string s,
            std::vector<std::vector<std::string>>* result,
            std::vector<std::string>* current,
            int start,
            int end) {
        if (start == end) {result->push_back(*current);}

        for (size_t i = start; i < end; i++) {
            std::string candidate = s.substr(start, i - start + 1);
            if (isPalindrome(candidate)) {
                current->push_back(candidate);
                helper(s, result, current, i + 1, end);
                current->pop_back();
            }
        }
    }

    bool isPalindrome(const std::string& s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length()-1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
