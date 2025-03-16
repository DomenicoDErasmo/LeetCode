#include <unordered_set>  // max, unordered_set
#include <vector>         // max, vector

class Solution {
   public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> vals(nums.begin(), nums.end());
        int result = 0;

        for (int num : vals) {
            if (!vals.count(num - 1)) {
                int length = 1;
                while (vals.count(num + length)) {
                    length++;
                }
                result = std::max(result, length);
            }
        }

        return result;
    }
};
