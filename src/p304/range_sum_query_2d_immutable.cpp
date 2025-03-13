#include <vector>  // vector

class NumMatrix {
   public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        std::vector<std::vector<int>> prefixSumToBuild(
            matrix.size(), std::vector<int>(matrix.front().size(), 0));

        // init first col
        for (int i = 0; i < prefixSumToBuild.size(); i++) {
            prefixSumToBuild[i][0] = matrix[i][0];
        }

        // fill each row
        for (int i = 0; i < prefixSumToBuild.size(); i++) {
            for (int j = 1; j < prefixSumToBuild[i].size(); j++) {
                prefixSumToBuild[i][j] =
                    prefixSumToBuild[i][j - 1] + matrix[i][j];
            }
        }

        prefixSum = prefixSumToBuild;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (int i = row1; i <= row2; i++) {
            result +=
                prefixSum[i][col2] - (col1 == 0 ? 0 : prefixSum[i][col1 - 1]);
        }

        return result;
    }

   private:
    std::vector<std::vector<int>> prefixSum;
};
