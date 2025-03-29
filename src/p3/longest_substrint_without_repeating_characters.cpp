#include <optional>       // optional
#include <string>         // string
#include <unordered_set>  // min, unordered_set

class Solution {
   public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> chars;
        int left = 0;
        std::optional<int> maxLength = std::nullopt;
        for (int i = 0; i < s.length(); i++) {
            while (chars.count(s[i])) {
                chars.erase(s[left]);
                left++;
            }
            chars.insert(s[i]);
            int currentLength = i - left + 1;
            maxLength = maxLength.has_value()
                            ? std::max(currentLength, maxLength.value())
                            : currentLength;
        }
        return maxLength.value_or(0);
    }
};
