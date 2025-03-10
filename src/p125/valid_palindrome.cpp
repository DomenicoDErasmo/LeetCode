#include <string>  // string

class Solution {
   public:
    bool isPalindrome(std::string s) {
        std::string cleaned_string;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z') {
                cleaned_string.push_back(ch);
            }

            if (ch >= 'A' && ch <= 'Z') {
                cleaned_string.push_back(ch + ' ');
            }
        }

        int left = 0, right = cleaned_string.size() - 1;
        while (left < right) {
            if (cleaned_string[left] != cleaned_string[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
