#include <vector>

class Solution {
   public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> subProblems(m + 1, std::vector<int>(n + 1, 0));
        // base cases
        for (int i = 1; i < m + 1; i++) {
            subProblems[i][1] = 1;
        }

        for (int j = 1; j < n + 1; j++) {
            subProblems[1][j] = 1;
        }

        for (int i = 2; i < m + 1; i++) {
            for (int j = 2; j < n + 1; j++) {
                subProblems[i][j] = subProblems[i-1][j] + subProblems[i][j-1];
            }
        }
        return subProblems.back().back();
    }
};
