#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // get the row
        size_t row = binaryGetRow(matrix, target);
        if (row == matrix.size()) return false;
        
        // search the row
        return binaryRowSearch(matrix[row], target);
    }
private:
    size_t binaryGetRow(const std::vector<std::vector<int>>& matrix, const int& target) {
        int start = 0, end = matrix.size() - 1;
        while (start <= end) {
            // safe in case start + end goes over int limit, although that shouldn't happen for this problem
            int mid = start + (end - start) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][matrix[mid].size() - 1]) return mid;
            else if (matrix[mid][matrix[mid].size() - 1] < target) start = mid + 1;
            else end = mid - 1;
        }
        // setting some illegal value for returning false
        return matrix.size();
    }
    
    bool binaryRowSearch(const std::vector<int>& row, const int& target) {
        int start = 0, end = row.size() - 1;
        while (start <= end) {
            // safe in case start + end goes over int limit, although that shouldn't happen for this problem
            int mid = start + (end - start)  / 2;
            if (row[mid] == target) return true;
            else if (row[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}