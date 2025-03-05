#include <string>
#include <vector>

class Solution {
   public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        return recursion(text1, text2);
    }

   private:
    int tabulation(std::string text1, std::string text2) {
        int m = text1.length(), n = text2.length();
        std::vector<std::vector<int>> subProblems(m + 1,
                                                  std::vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                int pickBoth = (text1[i - 1] == text2[j - 1] ? 1 : 0) +
                               subProblems[i - 1][j - 1];
                int pickLeft = subProblems[i - 1][j];
                int pickRight = subProblems[i][j - 1];
                subProblems[i][j] =
                    std::max(pickBoth, std::max(pickLeft, pickRight));
            }
        }
        return subProblems.back().back();
    }

    int recursion(std::string text1, std::string text2) {
        return helper(text1, text2, 0, 0);
    }
    int helper(std::string text1, std::string text2, int index1, int index2) {
        if (index1 >= text1.length() || index2 >= text2.length()) {
            return 0;
        }

        int pickBoth = (text1[index1] == text2[index2] ? 1 : 0) +
                       helper(text1, text2, index1 + 1, index2 + 1);
        int pickLeft = helper(text1, text2, index1 + 1, index2);
        int pickRight = helper(text1, text2, index1, index2 + 1);
        return std::max(pickBoth, std::max(pickLeft, pickRight));
    }
};
