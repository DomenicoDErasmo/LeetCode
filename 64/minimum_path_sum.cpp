#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        std::vector<std::vector<long>> sums(grid.size(), std::vector<long>(grid[0].size(), 0));
        sums[grid.size() - 1][grid[0].size() - 1] = grid[grid.size() - 1][grid[0].size() - 1];
        
        // base case: right row
        for (int i = grid.size() - 2; i >= 0; i--) {
            sums[i][grid[0].size() - 1] = grid[i][grid[0].size() - 1] + sums[i+1][grid[0].size() - 1];
        }
        
        // base case: bottom row
        for (int i = grid[0].size() - 2; i >= 0; i--) {
            sums[grid.size() - 1][i] = grid[grid.size() - 1][i] + sums[grid.size() - 1][i+1];
        }
        
        for (int i = grid.size() - 2; i >= 0; i--) {
            for (int j = grid[0].size() - 2; j >= 0; j--) {
                sums[i][j] = grid[i][j] + std::min(sums[i+1][j], sums[i][j+1]);
            }
        }
        
        return sums[0][0];
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}