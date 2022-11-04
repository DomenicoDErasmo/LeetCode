#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> result;
        for (size_t i = 0; i < n; i++) {
            result.push_back({});
            for (size_t j = 0; j < n; j++) {
                result[i].push_back(0);
            }
        }
        helper(result, 1, 0, n);
        return result;
    }
private:
    void helper(std::vector<std::vector<int>>& result, int current, int row_start, int row_end) {
        if (row_start >= row_end) {return;}
        if (row_start + 1 == row_end) {
            result[row_start][row_start] = current;
            return;
        }
        
        for (int i = row_start; i < row_end - 1; i++) {
            result[row_start][i] = current;
            current++;
        }
        
        for (int i = row_start; i < row_end - 1; i++) {
            result[i][row_end - 1] = current;
            current++;
        }
        
        for (int i = row_end - 1; i > row_start; i--) {
            result[row_end - 1][i] = current;
            current++;
        }
        
        for (int i = row_end - 1; i > row_start; i--) {
            result[i][row_start] = current;
            current++;
        }
        
        helper(result, current, row_start + 1, row_end - 1);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}