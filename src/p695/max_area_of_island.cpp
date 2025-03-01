#include <vector>
#include <iostream>

template <typename T>
using Grid = std::vector<std::vector<T>>;

template <typename T>
using Row = std::vector<T>;

class Solution {
   public:
    int maxAreaOfIsland(Grid<int>& grid) {
        Grid<bool> visited =
            Grid<bool>(grid.size(), Row<bool>(grid[0].size(), false));

        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // std::cout << "getting area for i=" << i << ", j=" << j << std::endl;
                int currentArea = helper(grid, visited, i, j);
                // std::cout << "area for i=" << i << ", j=" << j << " is " << currentArea << std::endl;
                maxArea = std::max(maxArea, currentArea);
            }
        }

        return maxArea;
    }

   private:
    int helper(const Grid<int>& grid, Grid<bool>& visited, int row, int col) {
        // std::cout << "calling helper on row=" << row << ", col=" << col << std::endl;
        if (outOfBounds(grid, row, col) || isWater(grid, row, col) ||
            alreadyVisited(visited, row, col)) {
            // std::cout << "area for subproblem row=" << row << ", col=" << col << " is 0" << std::endl;
            return 0;
        }

        visited[row][col] = true;
        int left = helper(grid, visited, row, col - 1);
        int up = helper(grid, visited, row - 1, col);
        int right = helper(grid, visited, row, col + 1);
        int down = helper(grid, visited, row + 1, col);

        // std::cout << "area for subproblem row=" << row << ", col=" << col << " is " << 1 + left + up + right + down << std::endl;
        return 1 + left + up + right + down;
    }

    bool outOfBounds(const Grid<int>& grid, int row, int col) {
        bool outOfBounds = row < 0 || row >= grid.size() || col < 0 ||
               col >= grid[0].size();
        if (outOfBounds) {
            // std::cout << "out of bounds" << std::endl;
        }
        return outOfBounds;
    }

    bool isWater(const Grid<int>& grid, int row, int col) {
        bool isWater = grid[row][col] == 0;
        if (isWater) {
            // std::cout << "is water" << std::endl;
        }
        return isWater;
    }

    bool alreadyVisited(const Grid<bool>& visited, int row, int col) {
        bool alreadyVisited = visited[row][col];
        if (alreadyVisited) {
            // std::cout << "alrady visited" << std::endl;
        }
        return alreadyVisited;
    }
};
