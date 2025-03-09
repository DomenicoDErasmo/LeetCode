#include <string>         //string
#include <unordered_set>  // unordered_set

class Solution {
   public:
    int lengthOfLongestSubstring(std::string s) {
        int right = 0;
        std::unordered_set<char> chars;
        while (right < s.size() && chars.find(s[right]) == chars.end()) {
            chars.insert(s[right]);
            right++;
        }

        int left = 0, maxLength = right - left;

        while (right < s.length()) {
            char current = s[right];
            if (chars.find(current) != chars.end()) {
                while (chars.find(current) != chars.end()) {
                    chars.erase(s[left]);
                    left++;
                }
            }
            chars.insert(current);
            right++;
            maxLength = std::max(maxLength, right - left);
        }

        return maxLength;
    }
};
