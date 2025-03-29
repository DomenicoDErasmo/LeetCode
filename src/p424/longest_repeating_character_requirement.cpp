#include <optional>       // optional
#include <string>         // max, string
#include <unordered_map>  // unordered_map

class Solution {
   public:
    int characterReplacement(std::string s, int k) {
        int left = 0;
        std::optional<int> maxLength = std::nullopt,
                           maxFrequency = std::nullopt;
        std::unordered_map<char, int> frequencies;

        for (int i = 0; i < s.length(); i++) {
            frequencies[s[i]]++;
            int currentFrequency = frequencies[s[i]];
            maxFrequency =
                maxFrequency.has_value()
                    ? std::max(maxFrequency.value(), currentFrequency)
                    : currentFrequency;

            // only need to check distance between max frequency letter
            // and string with all of that letter (i.e. size - max frequency)
            while (distance(left, i) - maxFrequency.value() > k) {
                frequencies[s[left]]--;
                left++;
            }
            maxLength = maxLength.has_value()
                            ? std::max(maxLength.value(), distance(left, i))
                            : distance(left, i);
        }

        return maxLength.value_or(0);
    }

   private:
    int distance(int left, int right) { return right - left + 1; }
};
