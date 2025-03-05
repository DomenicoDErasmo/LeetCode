#include <vector>

class Solution {
   public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        int n = obstacleGrid[0].size();

        std::vector<std::vector<int>> subProblems(m + 1,
                                                  std::vector<int>(n + 1, 0));
        // base cases
        bool foundObstacleInStartRow = false;
        for (int i = 1; i < m + 1; i++) {
            if (obstacleGrid[i - 1][0] == 1) {
                foundObstacleInStartRow = true;
            }
            subProblems[i][1] = foundObstacleInStartRow ? 0 : 1;
        }

        bool foundObstacleInStartCol = false;
        for (int j = 1; j < n + 1; j++) {
            if (obstacleGrid[0][j - 1] == 1) {
                foundObstacleInStartCol = true;
            }
            subProblems[1][j] = foundObstacleInStartCol ? 0 : 1;
        }

        for (int i = 2; i < m + 1; i++) {
            for (int j = 2; j < n + 1; j++) {
                subProblems[i][j] =
                    obstacleGrid[i - 1][j - 1] == 1
                        ? 0
                        : subProblems[i - 1][j] + subProblems[i][j - 1];
            }
        }
        return subProblems.back().back();
    }
};
