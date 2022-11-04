#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacle_grid) {
        // init table - all zeroes except for bottom-right cell (unless it isn't reachable)
        std::vector<std::vector<long>> table;
        for (size_t i = 0; i < obstacle_grid.size(); i++) {
            std::vector<long> row(obstacle_grid[0].size(), 0);
            table.push_back(row);
        }
        if (!obstacle_grid[obstacle_grid.size() - 1][obstacle_grid[0].size() - 1]) {table[table.size() - 1][table[0].size() - 1] = 1;}
        
        // base case: right side
        for (int i = obstacle_grid.size() - 2; i >= 0; i--) {
            if (obstacle_grid[i][obstacle_grid[0].size() - 1]) {
                table[i][obstacle_grid[0].size() - 1] = 0;
            } else {
                table[i][obstacle_grid[0].size() - 1] = table[i+1][obstacle_grid[0].size() - 1];
            }
        }
        
        // base case: bottom side
        for (int i = obstacle_grid[0].size() - 2; i >= 0; i--) {
            if (obstacle_grid[obstacle_grid.size() - 1][i]) {
                table[obstacle_grid.size() - 1][i] = 0;
            } else {
                table[obstacle_grid.size() - 1][i] = table[obstacle_grid.size() - 1][i+1];
            }
        }
        
        // general case: if an obstacle, mark with 0, otherwise add bottom and right
        for (int i = obstacle_grid.size() - 2; i >= 0; i--) {
            for (int j = obstacle_grid[0].size() - 2; j >= 0; j--) {
                if (obstacle_grid[i][j]) {
                    table[i][j] = 0;
                } else {
                    table[i][j] = table[i+1][j] + table[i][j+1];
                }
            }
        }
        
        return table[0][0];
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}