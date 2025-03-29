#include <vector>  // vector

class NumMatrix {
   public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        std::vector<std::vector<int>> initPrefixRangeSum(
            matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                initPrefixRangeSum[i + 1][j + 1] =
                    initPrefixRangeSum[i][j + 1] +
                    initPrefixRangeSum[i + 1][j] - initPrefixRangeSum[i][j] +
                    matrix[i][j];
            }
        }
        prefixRangeSum = initPrefixRangeSum;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixRangeSum[row2 + 1][col2 + 1] + prefixRangeSum[row1][col1] -
               prefixRangeSum[row1][col2 + 1] - prefixRangeSum[row2 + 1][col1];
    }

   private:
    std::vector<std::vector<int>> prefixRangeSum;
};
