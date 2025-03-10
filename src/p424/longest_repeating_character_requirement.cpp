#include <string>         // string
#include <unordered_map>  // unordered_map

class Solution {
   public:
    int characterReplacement(std::string s, int k) {
        std::unordered_map<char, int> count;
        int result = 0;

        int left = 0, maxFrequency = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            maxFrequency = std::max(maxFrequency, count[s[right]]);

            while ((right - left + 1) - maxFrequency > k) {
                count[s[left]]--;
                left++;
            }
            result = std::max(result, right - left + 1);
        }

        return result;
    }
};
