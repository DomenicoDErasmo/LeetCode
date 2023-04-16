#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        return helper(matrix, 0, matrix.size(), 0, matrix[0].size());
    }
private:
    std::vector<int> helper(const std::vector<std::vector<int>>& matrix, const int& row_start, const int& row_end, const int& col_start, const int& col_end) {
        std::vector<int> result;
        bool more_cells = true;
        
        if (more_cells) {
            more_cells = false;
            for (int i = col_start; i < col_end; i++) {
                result.push_back(matrix[row_start][i]);
                more_cells = true;
            }
        }
        
        if (more_cells) {
            more_cells = false;
            // For these three loops, we alredy printed the first element in the row, so we start with the next element
            for (int i = row_start + 1; i < row_end; i++) {
                result.push_back(matrix[i][col_end - 1]);
                more_cells = true;
            }
        }
        
        if (more_cells) {
            more_cells = false;
            for (int i = (col_end - 1) - 1; i >= col_start; i--) {
                result.push_back(matrix[row_end - 1][i]);
                more_cells = true;
            }
        }
        
        if (more_cells) {
            more_cells = false;
            for (int i = (row_end - 1) - 1; i >= row_start + 1; i--) {
                result.push_back(matrix[i][col_start]);
                more_cells = true;
            }
        }
        
        // do we have a smaller rectangle? if so, get it in spiral order and append, then return
        if (row_start + 2 < row_end && col_start + 1 < col_end) {
            std::vector<int> subrectangle = helper(matrix, row_start + 1, row_end - 1, col_start + 1, col_end - 1);
            result.insert(result.end(), subrectangle.begin(), subrectangle.end());
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}