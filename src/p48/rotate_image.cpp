#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        helper(matrix, 0, matrix.size() - 1);
    }
private:
    void helper(std::vector<std::vector<int>>& matrix, int start, int end) {
        if (start >= end) {return;}
        
        for (size_t i = 0; i < end - start; i++) {
            int temp = matrix[start][start+i];
            matrix[start][start+i] = matrix[end-i][start];
            matrix[end-i][start] = matrix[end][end-i];
            matrix[end][end-i] = matrix[start+i][end];
            matrix[start+i][end] = temp;
        }
        
        helper(matrix, start + 1, end - 1);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}