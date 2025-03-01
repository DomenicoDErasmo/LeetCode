#include <vector>

class Solution {
   public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        std::vector<std::vector<bool>> visited = std::vector<std::vector<bool>>(
            grid.size(), std::vector<bool>(grid[0].size(), false));

        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                result += helper(grid, visited, i, j);
            }
        }
        return result;
    }

   private:
    int helper(const std::vector<std::vector<char>>& grid,
               std::vector<std::vector<bool>>& visited, int row, int col) {
        if (outOfBounds(grid, row, col) || isWater(grid, row, col) ||
            alreadyVisited(visited, row, col)) {
            return 0;
        }

        visited[row][col] = true;
        int up = helper(grid, visited, row - 1, col);
        int right = helper(grid, visited, row, col + 1);
        int down = helper(grid, visited, row + 1, col);
        int left = helper(grid, visited, row, col - 1);

        return 1;
    }

    bool outOfBounds(const std::vector<std::vector<char>>& grid, int row,
                     int col) {
        return row < 0 || row >= grid.size() || col < 0 ||
               col >= grid[0].size();
    }

    bool isWater(const std::vector<std::vector<char>>& grid, int row, int col) {
        return grid[row][col] == '0';
    }

    bool alreadyVisited(const std::vector<std::vector<bool>>& visited, int row,
                        int col) {
        return visited[row][col];
    }
};
