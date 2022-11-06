#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::set<size_t> rows_to_zero, cols_to_zero; 
        
        // populate set
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows_to_zero.insert(i);
                    cols_to_zero.insert(j);
                }
            }
        }
        
        // iterate over matrix and check if in the set
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                if (rows_to_zero.find(i) != rows_to_zero.end() || cols_to_zero.find(j) != cols_to_zero.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}